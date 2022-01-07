/*


큐를 이용해 우선순위가 낮으면 쌓고 우선순위 큰거를 찾으면 다시 원래 vector에 넣고 

처음 대기 위치 key로 해서 prirory와 나온 순서를 저장
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q2;
    queue<pair<int, int>> q1;
    vector<pair<int, int>> vec;
    map<int, pair<int, int>> mp; //key가 대기 location , value  최종 위치, 우선순위

    for (int i = 0; i < priorities.size(); i++)
    {
        mp[i] = make_pair(i, priorities[i]);
        // mp.insert({i,make_pair(i,priorities[i])});
        q1.push(make_pair(i, priorities[i]));
    }

    while (!q1.empty())
    {
        pair<int, int> fro = make_pair(q1.front().first, q1.front().second);
        q1.pop();
        for (int i = 0; i < q1.size(); i++)
        {
            if(fro.second>q1.front().second){
                q2.push(make_pair(q1.front().first, q1.front().second));
                q1.pop();
            }
            else{
                q1.push(make_pair(fro.first,fro.second));
                while(!q2.empty()){
                    q1.push(make_pair(q2.front().first,q2.front().second));
                    q2.pop();
                }

            }
        }
    }
    for (auto m : mp)
    {
        cout << m.first << ' ' << m.second.first << ' ' << m.second.second << '\n';
    }
    return answer;
}

int main()
{

    solution({1, 2, 3, 4, 5}, 2);
}