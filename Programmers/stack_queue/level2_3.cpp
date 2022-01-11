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
        if(!bridge.empty()&&(bridge.front().second)==(bridge_length)  )
        {
            int current_count = bridge.front().second;
            bridge_capacity+=bridge.front().first;
           
            bridge.pop();
            if(!bridge.empty())
            bridge.front().second = bridge_length-1;
        }
        if(!bridge.empty())
        {
            bridge.front().second += 1;
        }
        if (!tw.empty()&&bridge_capacity >= tw.front() && bridge.size() != bridge_length)
        {

            bridge.push(make_pair(tw.front(), 1));
            bridge_capacity -= tw.front();
            tw.pop();

        }
        else if(!tw.empty()&&bridge_capacity < tw.front()&& bridge.size() != bridge_length){
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