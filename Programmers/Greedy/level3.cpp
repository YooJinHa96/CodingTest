#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#define INF (int)1e9
using namespace std;
int graph[100][100];

void Print_graph(int n, vector<vector<int>> v)
{
    int g[100][100];
    cout<<"  ";
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {

        cout << i << ' ';
        for (int k = 0; k < n; k++)
        {
            g[i][k] = graph[i][k];
            cout << graph[i][k] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {

        cout << i << ' ';
        for (int k = 0; k < n; k++)
        {
            if (v[i][k] != -1)
            {
                if(i==1&&k==3){
                    cout<<v[i][k]<<'\n';
                    return;
                }
                g[i][k] -= graph[i][v[i][k]];
            }
            cout << g[i][k] << ' ';
        }
        cout << '\n';
    }
}
int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> visit(n, INF);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        fill(graph[i], graph[i] + n, INF);
    }
    for (int i = 0; i < n; i++)
    { //자기 자신 비용 = 0
        for (int k = 0; k < n; k++)
        {
            if (i == k)
            {
                graph[i][k] = 0;
            }
        }
    }
    for (int i = 0; i < costs.size(); i++)
    {
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    int m = 0;
    vector<vector<int>> minus(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < n; k++)
        {

            for (int q = 0; q < n; q++)
            {
                m = graph[k][i] + graph[i][q];
                 
                if (graph[k][q] >m)
                {
                    if(k==1&&q==3){
                        cout<<i<<'\n';
                    }    
                    graph[k][q] = m;
                    minus[k][q] = i;
                }
                // graph[k][q] = min(graph[k][q], graph[k][i] + graph[i][q]);
                
            }
        }
    }
    vector<int> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sum[i] += graph[i][k];
            if (minus[i][k] != -1)
            {
                sum[i] -= graph[i][minus[i][k]];
            }
        }
    }
    int min_index;
    for (int i = 0; i < n; i++)
    {
        if (sum[i] == *min_element(sum.begin(), sum.end()))
        {
            min_index = i;
            break;
        }
    }
    Print_graph(n, minus);

    // for (int i = 0; i <n; i++)
    //{

    //  if (minus[min_index][i] != -1)
    //  {

    //      sum[min_index] -= graph[min_index][minus[min_index][i]];
    // }
    // }

    answer = sum[min_index];
    cout << min_index << ' ';
    return answer;
}

int main()
{

    // int answer = solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});
    // int answer=solution(5,{{0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4},{2,4,6},{4,0,5}});
    int answer = solution(6, {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}});

    cout << answer << '\n';
}