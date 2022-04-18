#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int dx[] = {1, 0, -1, 0,1,};
int dy[] = {0, 1, 0, -1,-1};
int N;
bool check_move(pair<int,int> p1, pair<int,int> p2){

    if(0<=p1.first&&p1.first<N && 0<=p1.second && p1.second<N && 0<=p2.first&&p2.first<N && 0<=p2.second && p2.second<N){
        return true;
    }
    else{
        return false;
    }
}
bool check_rotation( int d, pair<int,int> axix,pair<int,int> p ){
    //d == 짝수 -> 시계방향 홀수 반시계방향
    if(d%2==0){
        if(p.first)
    }
    else
    {

    }
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    map<pair<pair<int, int>, pair<int, int>>, bool> visit;
    N = board.size();
    q.push({{0, 0}, {0, 1}});
    visit[{{0, 0}, {0, 1}}] = true;
    visit[{{0, 1}, {0, 0}}] = true;
    while (!q.empty())
    {
        int x1 = q.front().first.first, y1 = q.front().first.second;
        int x2 = q.front().second.first, y2 = q.front().second.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
            {
                int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i], ny2 = y2 + dy[i];
                if(check_move({nx1,ny1},{nx2,ny2}) && !visit[{{nx1,ny1},{nx2,ny2}}] && board[nx1][ny1]==0 && board[nx2][ny2]==0){
                    q.push({{nx1,ny1},{nx2,ny2}});
                    visit[{{nx1,ny1},{nx2,ny2}}]=true;
                    visit[{{nx2,ny2},{nx1,ny1}}]=true;
                }
            }
            else if (3 < i && i < 6) //뒤축
            {
                int nx=-(y2-y1)+x1;
                int ny=(x2-x1)+y1;
                if(check_rotation(i%2,{x1,y1},{x2,y2})){

                }
                else{

                }

            }
            else if (5 < i && i < 8) //앞축
            {

            }
        }
    }
    return answer;
}