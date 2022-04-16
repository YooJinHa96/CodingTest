#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M;
int graph[8][8];
int wall_graph[8][8];
int sol_graph[8][8];
vector<int> ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS()
{
    copy(&wall_graph[0][0], &wall_graph[0][0] + 64, &sol_graph[0][0]);
  
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> visit;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (sol_graph[i][j] == 2)
            {
                q.push({i, j});
      
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M  && sol_graph[nx][ny] == 0)
            {
                
                sol_graph[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (sol_graph[i][j] == 0)
            {
                count++;
            }
        }
    }
    ans.push_back(count);
}
void make_wall(int count)
{
    if (count == 3)
    {
        BFS();
        return ;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < M; j++)
            {
                if (count == 0)
                {

                    copy(&graph[0][0], &graph[0][0] + 64, &wall_graph[0][0]);
                }

                if (wall_graph[i][j] == 0)
                {
                    wall_graph[i][j] = 1;
                    make_wall(count + 1);
                    wall_graph[i][j] = 0;
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    int a;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }
    make_wall(0);

    int answer = *max_element(ans.begin(), ans.end());

    cout << answer << '\n';
}