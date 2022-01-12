/*

Programmers 다리를 지나는 트럭

먼저들어온 값이 먼저 나가야하는 순서로 진행되야하므로 queue를 사용 vector로 주어진 트럭 무게들을 tw라는 queue에 넣어서 진행
다리의 현재 견딜수 있는 무게를 bridge_capacity 변수를 이용함 
bridge 큐는 pair를 써서  다리에 올라온 트럭의 무게랑 시간을 넣 었음 first -> 트럭 무게, 시간(brdgie_lenge(다리길이)만큼 카운트하기 위해) 
bridge 큐에 push 할때 bridge_capacity에서 트럭의 무게를 빼서 다리가 견딜 수 있는 무게를 계산  (트럭이 올라왔으므로 견딜수 있는 무게가 줄어듬)
진행하면서 큐에 제일 앞값 second 즉 시간(다리한칸)에만 +1를 진행 -> 그렇게 진행하다 다리에 길이랑 맞아지면  pop시키고  빠져 나온 트럭의 무게는 bridge_capacity에 플러스 시킴(트럭이 빠졋으므로 견딜수 있는 무게가 늘음)
그리고 원래는 큐안에 다른 값들도 한값씩 이동했어야 하기 때문에 다음 큐값에 second 값에는 총 이동해야 할 다리의 길이에 -1 을 함 -> pop시킬 때 빠져나오는 트럭 위치 바로 다음칸에 있다고 판단
중간에 다리 무게가 못견뎌서 트럭이 못들어올때는 (0,0)값을 넣어줌.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int time = 0;
    queue<int> tw;
    queue<pair<int, int>> bridge;
    int bridge_capacity = weight;
    int count = 0;

    for (int i = 0; i < truck_weights.size(); i++)
    {
        tw.push(truck_weights[i]);
       
    }
    while (!tw.empty() || !bridge.empty())
    {
          time++;
        if(!bridge.empty()&&(bridge.front().second)==(bridge_length)  ) //다리의 첫번 째 트럭이 다리 길이만큼 갔을때
        {

            bridge_capacity+=bridge.front().first;
           
            bridge.pop();
            if(!bridge.empty())
            bridge.front().second = bridge_length-1;
        }
        if(!bridge.empty()) // 한칸씩 이동
        {
            bridge.front().second += 1;
        }
        if (!tw.empty()&&bridge_capacity >= tw.front() && bridge.size() != bridge_length) //다리에 새로운 트럭이 들어올수 있는지 확인
        {

            bridge.push(make_pair(tw.front(), 1));
            bridge_capacity -= tw.front();
            tw.pop();

        }
        else if(!tw.empty()&&bridge_capacity < tw.front()&& bridge.size() != bridge_length){// 못들어오면 0으로 채움
            bridge.push(make_pair(0,0));

        }

        
     
    }
    answer=time ;
    return answer;
}
int main(){
    int num;
    int num1=solution(100,100,{10});
    int num2=solution(2,10,{7,4,5,6});
    int num3=solution(100,100,{10,10,10,10,10,10,10,10,10,10});
    std:: cout<<num1<<'\n';
    std:: cout<<num2<<'\n';
    std:: cout<<num3<<'\n';
}