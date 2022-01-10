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

    int count = 0;
    while (!q1.empty() || !q2.empty())
    {
        pair<int, int> fro = make_pair(q1.front().first, q1.front().second);
        q1.pop();
        int size = q1.size();
        while (!q1.empty())
        {
            if (fro.second >= q1.front().second)
            {
                q2.push(make_pair(q1.front().first, q1.front().second));
                q1.pop();
            }
            else
            {
                q1.push(make_pair(fro.first, fro.second));
                while (!q2.empty())
                {
                    q1.push(make_pair(q2.front().first, q2.front().second));
                    q2.pop();
                }
                fro = make_pair(q1.front().first, q1.front().second);
                q1.pop();
            }
        }

        count++;
        mp[fro.first].first = count;

        while (!q2.empty())
        {
            q1.push(make_pair(q2.front().first, q2.front().second));
            q2.pop();
        }

    }


    answer = mp[location].first;
    return answer;
}

int main()
{

    int s = solution({1, 1, 9, 1, 1, 1}, 0);
    cout << s << '\n';
}