#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector<string> graph;
vector<vector<vector<bool>>> visit;
queue<pair<pair<int, int>, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int N, M;
    int num;
    vector<int> ans;
    int answer = -1;
    map<int, vector<int>> mp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        vector<vector<bool>> b;
        graph.push_back(s);
        visit.push_back(b);
        for (int k = 0; k < M; k++)
        {
            vector<bool> b;
            visit[i].push_back(b);
            visit[i][k].push_back(false);
            visit[i][k].push_back(false);
        }
    }

    q.push({{0, 0}, 0});
    visit[0][0][0] = true; // 0 -> 벽을 안부수고 방문
    visit[0][0][1] = true; // 0 -> 벽을 부수고 방문
    int count = 0;
    bool flag = false;
    while (!q.empty())
    {
        int s = q.size();
        count++;

        for (int i = 0; i < s; i++)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int wall = q.front().second;
            q.pop();
            if (x == (N - 1) && y == M - 1)
            {
                ans.push_back(count);
                //break;
            }
            for (int j = 0; j < 4; j++)

            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (0 <= nx && nx < N && 0 <= ny && ny < M)
                {
                    if (graph[nx][ny] == '1' && !visit[nx][ny][1])
                    {
                        if (wall==0)
                        {
                            visit[nx][ny][1] = true;
                            q.push({{nx, ny}, 1});
                        }
                    }
                    else if (graph[nx][ny] == '0')
                    {
                        if (!visit[nx][ny][wall])
                        {
                            visit[nx][ny][wall] = true;
                            q.push({{nx, ny}, wall});
                        }
                    }
                }
            }
        }
    }
    if (ans.size() != 0)
    {
        answer = *min_element(ans.begin(), ans.end());
    }
    cout << answer << '\n';
}