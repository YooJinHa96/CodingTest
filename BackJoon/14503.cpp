#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[51][51];
struct robot
{
    int r, c;
    int d;
} typedef robot;

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
    switch ((d + 1) / 4)
    {
    case 0:
        if (arr[r + 1][c] != 1)
            b = true;
        break;
    case 1:
        if (arr[r][c + 1] != 1)
            b = true;
        break;
    case 2:
        if (arr[r - 1][c] != 1)
            b = true;
        break;
    case 3:
        if (arr[r][c - 1] != 1)
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

    robot ro;
    ro.r = r;
    ro.c = c;
    ro.d = d;
    int d_N[4] = {-1, 0, 1, 0};
    int d_M[4] = {0, 1, 0, -1};
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            cin >> arr[i][k];
        }
    }
    int count = 1;
    while (1)
    {
        if (exit_con(ro.r, ro.c))
        {
            if (arr[ro.r - d_N[ro.d] ][ro.c - d_M[ro.d] ] == 2)
            {
                ro.r -= d_N[ro.d];
                ro.c -= d_M[ro.d];
            }
            else if (arr[ro.r - d_N[ro.d]][ro.c - d_M[ro.d]] == 1)
            {
                break;
            }
        }
        else if (go_left(ro.r, ro.c, ro.d))
        {
            ro.d = (ro.d + 1) / 4;
            ro.r += d_N[ro.d];
            ro.c += d_M[ro.d];
            if (arr[ro.r][ro.c] == 0)
            {
                arr[ro.r][ro.c] =2;
                count++;
            }
        }
        else{
            ro.d=(ro.d+1)/4;
        }
    }
    cout << count << '\n';
}