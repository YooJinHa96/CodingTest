#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    int N, M;
    int graph[8][8];
    int count = 0;
    int answer = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<pair<int, int>, int>> q; // x,y,wall_count
    bool visit[8][8][4];
    vector<int> ans;
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            cin >> a;
            graph[i][k] = a;
            if (a == 2)
            {
                q.push({{i, k}, 0});
            }
        }
    }
    if (q.empty())
    {
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < M; k++)
            {
                if (graph[i][k] == 0)
                {
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }
    else
    {
        while (!q.empty())
        {

            count++;
            int s = q.size();
            for (int k = 0; k < s; k++)
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int wall_count = q.front().second;
                q.pop();
                if(x==N-1&&y==M-1){
                    ans.push_back((N*M)-count+3);
                }
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                     if (0 <= nx && nx < N && 0 <= ny && ny < M)
                    {

                        if (graph[nx][ny] == 0 && !visit[nx][ny][wall_count])
                        {
                            visit[nx][ny][wall_count] = true;
                            q.push({{nx, ny}, wall_count});
                        }
                    }
                }
            }
        }
    }
}