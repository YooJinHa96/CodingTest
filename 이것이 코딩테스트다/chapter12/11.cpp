#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int N;
    int K;
    int x, y;
    int direction;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int tail_x, tail_y;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    map<pair<int, int>, bool> body;

    queue<pair<int, int>> q;
    queue<pair<int, char>> d;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }
    int t, L;
    char c;
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> t >> c;
        d.push({t, c});
    }
    int time = 0;
    tail_x = 0;
    tail_y = 0;
    x = 0;
    y = 0;
    body[{x,y}]=true;
    q.push({0,0});
    int d_index = 1;
    while (1)
    {
        int nx = x + dx[d_index];
        int ny = y + dy[d_index];
        //q.push({x,y});
        time++;
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !body[{nx, ny}])
        {
            body[{nx,ny}]=true;
            q.push({nx,ny});
            if (board[nx][ny] == 1)
            {
                board[nx][ny]=0;
                          
            }
            else
            {
                if (!q.empty())
                {
                    body[{q.front().first, q.front().second}] = false;
                    q.pop();
                    
                }
               
            }
        }
        else
        {
      
            break;
        }
        if (!d.empty()&&time == d.front().first)
        {
            if (d.front().second == 'D')
            {
                d_index++;
                d_index %= 4;
            }
            else
            {
                d_index--;
                if (d_index < 0)
                {
                    d_index += 4;
                }
                d_index %= 4;
            }
            d.pop();
        }
        x = nx;
        y = ny;
    }
    cout << time << '\n';
    return 0;
}