#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[51][51];

bool exit_con(int r, int c)
{

    if (arr[r - 1][c] != 0 && arr[r + 1][c] != 0 && arr[r][c - 1] != 0 && arr[r][c + 1] != 0)
    {
        return true;
    }
    return false;
}
bool go_left(int r, int c, int d)
{

    bool b = false;
    switch ((d + 1) % 4)
    {
    case 0:
        if (arr[r - 1][c] == 0)
            b = true;
        break;
    case 1:
        if (arr[r][c - 1] == 0)
            b = true;
        break;
    case 2:
        if (arr[r + 1][c] == 0)
            b = true;
        break;
    case 3:
        if (arr[r][c + 1] == 0)
            b = true;
        break;

    default:
        break;
    }
    return b;
}
int main()
{

    int N, M;
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            cin >> arr[i][k];
        }
    }
    arr[r][c] = 2;
    int count = 1;
    while (1)
    {
      
        bool ch = false;
        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (arr[nx][ny] == 0)
            {
                r += dx[d];                
                c += dy[d];
                arr[nx][ny] = 2;
                ch = true;
                count++;
                break;
            }
        }
        if (!ch)
        {                           //조건 2-c , 2-d일 때
            int back = (d + 2) % 4; //바라보는 방향을 유지하기 위해서
            if (arr[r + dx[back]][c + dy[back]] == 1)
                break;
            r += dx[back];
            c += dy[back];
        }
    }
    cout << count << '\n';
}