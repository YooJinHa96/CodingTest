/*

Programmers 프린트

프린트가 우선순위를 따지면서 진행하는데 제일 앞에 있는게 작으면 뒤로 다시 돌아가는 식으로 풀어야함.

큐를 이용해 우선순위가 낮으면 쌓고 우선순위 큰거를 찾으면 다시 원래 vector에 넣고 

처음에는 map을 사용 key : 처음 대기 위치, value : 최종위치, 우선순위  
처음 대기 위치 key로 해서 prirory와 나온 순서를 저장
count변수를 이용해서 최종 위치 확인
q1, q2를 두개 사용 해서 q1에서 꺼내면서 확인 한다음 우서순위가 꺼낸것이 다음 q1에 있는 것보다 우선순위가 높으면 그대로 q1에 꺼낸 값을 q2에 넣는다.
만약에 q1에 처음에 꺼낸 것과 다음 q1에서 나온값중에 나온값이 우선순위가 더크면 처음에 꺼낸 것을 q1에 넣은 후 q2에 값들 을 제일 뒤로 넣는 방식 -> 이렇게해야 먼저 확인순서대로 q1에다시 들어감
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
 //   map<int, pair<int, int>> mp; //key가 대기 location , value  최종 위치, 우선순위

    for (int i = 0; i < priorities.size(); i++)
    {
      //  mp[i] = make_pair(i, priorities[i]);
        q1.push(make_pair(i, priorities[i]));
    }

    int count = 0;
    while (!q1.empty() || !q2.empty())
    {
        pair<int, int> fro = make_pair(q1.front().first, q1.front().second);
        q1.pop();
    
        while (!q1.empty())
        {
            if (fro.second >= q1.front().second)
            {
                q2.push(make_pair(q1.front().first, q1.front().second));
                q1.pop();
            }
            else // q2에값들과 나와있는 값 다시 q1에 넣는 작업
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
        if(fro.first==count){
            return count;
        }
     //   mp[fro.first].first = count;

        while (!q2.empty())  // 상태 : q1은 비어있을때 두번째 반복문에서 나오기 때문에 q1이 비어있음. 그래서 다시 q1으로 옮겨주는 작업
        {
            q1.push(make_pair(q2.front().first, q2.front().second));
            q2.pop();
        }

    }


}

int main()
{

    int s = solution({1, 1, 9, 1, 1, 1}, 0);
    cout << s << '\n';
}