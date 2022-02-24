
/*
 Programmers Greedy  level3 단속 카메라

 1. 출발지점을 기준으로 정렬 -> 순서대로 진행해야하기 때문에

    차량이 나가는 끝 지점을 기준으로 카메라 설치 위치를 정함
 2 . 처음 차가 나가는 구간을 final 값에 저장.

 3. 다음차가 현재차가 끝난후 들어오면 카메라를 추가 <- 현재차 구간에 카메라를 설치해야하기 떄문

 4. 현재차보다 다음차가 먼저 끝나면 final 값을 다음 차가 나가는 값으로 변경
   - 둘이 겹치는 부분에 카메라를 설치해야 1개로 2차를 다확인 할수 있기 때문에

  
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 1; //마지막차를 체크하기 위해
    int final=0;
    sort(routes.begin(),routes.end());
    final=routes[0][1];
    for(auto v : routes){
        if(final<v[0]){//현재차가 다음 차보다 먼저 끝났을 때 
        
            answer++;
            final=v[1];
        }
        else if(final>=v[1])final=v[1];//다음 차가 현재 차보다 먼저 끝났을 때 
    }



    return answer;
}
int main(){
    int answer=solution({{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}});
    cout<<answer<<'\n';
}