#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<pair<int, int>, pair<int, int>> pq;
int N, K;
int S, X, Y;
int graph[200][200];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{

    cin >> N >> K;
    // priority_queue<pair<int, pair<int, int>>> q;
    priority_queue<pq, vector<pq>, greater<pq>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
            {
                q.push({{0, graph[i][j]}, {i, j}});
            }
        }
    }
    cin >> S >> X >> Y;
    //int time = 0;
    while (!q.empty())
    {
        int time = q.top().first.first;
        int birus = q.top().first.second;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        time++;
        if(time==S+1){

            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx < N && 0<= ny && ny < N && graph[nx][ny]==0){
                graph[nx][ny]=birus;
                q.push({{time,graph[nx][ny]},{nx,ny}});
            }
        }
    }
  
    cout<<graph[X-1][Y-1]<<'\n';
}