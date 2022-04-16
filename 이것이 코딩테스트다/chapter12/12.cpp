#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    vector<vector<vector<int>>> graph(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    //[x][y] [0]==기동 [1] -> 보,
    // 0 -> 없음 1->있음

    // x,y -> 기둥, 보 좌표
    // a -> 0은 기둥 1=보
    // b -> 0은 삭제 1.설치
    //순서대로 진행

    for (int i = 0; i < build_frame.size(); i++)
    {

        //설치
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (b == 1)
        {
            if (a == 0)
            { //기둥 설치
                if (y == 0 || (x - 1 >= 0 && graph[x - 1][y][1] >= 1) || (y - 1 >= 0 && graph[x][y - 1][0] >= 1))
                {
                    graph[x][y][0] = 1;
                }
            }
            else
            { //보 설치
                if ((y - 1 >= 0 && graph[x][y - 1][0] == 1) || (x + 1 <= n && y - 1 >= 0 && graph[x + 1][y - 1][0] == 1) || (x + 1 <= n && graph[x + 1][y][1] == 1))
                {
                    graph[x][y][1] = 1;
                }
            }
        }
        else if (b == 0)
        { //삭제
            if (a == 0)
            { //기둥 삭제
                if ((y + 1 <= n) && (graph[x][y + 1][0] == 0 && graph[x][y + 1][1] == 0))
                {
                    graph[x][y][0]--;
                }
                else if ((y + 1 <= n) && (graph[x][y + 1][0] == 0 && graph[x][y + 1][1] >= 1))
                {
                    if (x - 1 >= 0 && graph[x - 1][y + 1][1] >= 1)
                    {
                        graph[x][y][0]--;
                    }
                    else if (x + 1 <= n && (graph[x + 1][y][0] == 1 || graph[x + 1][y + 1][1] == 1))
                    {
                        graph[x][y][0]--;
                    }
                }
            }
            else
            {
                bool check=true;
                if (x-1 >= 0 && graph[x-1][y][1]==1 )
                {
                    if(x-1>=0&& y-1>=0 && graph[x][y-1][0] == 0 && graph[x-1][y-1][0] == 0){
                        check=false;
                    }
                }
                if(graph[x+1][y][1]==1){
                    if(x-1>=0 && y-1>=0 && x+1 <=n && x+2<=n && graph[x+1][y-1][0]==0 && graph[x+2][y-1][0] == 0){
                        check=false;
                    }
                }
                if(check)
                graph[x][y][1]--;
            }
        }
    }
    vector<int> v;
    answer.push_back(v);
    int index = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int k = 0; k < n + 1; k++)
        {
            if (graph[i][k][0] >= 1)
            {
                // graph[i][k+1][;
                answer[index].push_back(i);
                answer[index].push_back(k);
                answer[index].push_back(0);
                answer.push_back(v);
                index++;
            }
            if (graph[i][k][1] >= 1)
            {
                answer[index].push_back(i);
                answer[index].push_back(k);
                answer[index].push_back(1);
                answer.push_back(v);
                index++;
            }
        }
    }
    answer.pop_back();
    return answer;
}

int main()
{
    vector<vector<int>> answer = solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});
    for (auto ans : answer)
    {
        for (auto a : ans)
        {
            cout << a << ' ';
        }
        cout << '\n';
    }
}