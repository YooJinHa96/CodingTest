#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#define INF (int)1e9
using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> visit(n, INF);
    queue<pair<int, int>> q;
    int graph[100][100];

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
    vector<int> minus(4,0);
    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < n; k++)
        {

            for (int q = 0; q < n; q++)
            {
                m = graph[k][i] + graph[i][q];
                if (graph[k][q] > m)
                {
                    graph[k][q]=m;
                    minus[k]+=graph[k][i];
                }
                graph[k][q] = min(graph[k][q], graph[k][i] + graph[i][q]);
            }
        }
    }
    vector<int> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sum[i] += graph[i][k];
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
    answer=sum[min_index]-minus[min_index];

    return answer;
}

int main()
{
    int answer = solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});
    cout<< answer<<'\n';
}