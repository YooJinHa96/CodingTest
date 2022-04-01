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
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    map<pair<int, int>, bool> tail;
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
    q.push({0, 0});
    while (1)
    {
        x=q.front().first;
        y=q.front().second;
        
    }
}