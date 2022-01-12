/*
Programmers 기능 개발 

스택/ 큐 -> level 2 -> 기능개발
작업 진도랑 개발 속도가 적힌 정수 배열이 주어질 때 각 배포마다 몇개 기능이 배포되는지 구하기
진행사항과 speeds를 이용해 하나당 걸리는 일수를 먼저 구해서 remains 큐에 다 넣음 계산 : (100 - progresses[]) /speeds -> 이때 나누어떨어지지 않는 것들도 있기 때문에 이럴때 +1시킴
다 구했으면 remains에서 제일 앞에 값을 꺼내서 다음 값들과 비교하며 작거나 같은 값들을 count\


테스트 11 반례 생긴 이유 : 조건문에서 a%=speeds[i]!=0을 해서 우선순위가 %기가 아닌 !=0이 먼저 되서 반례가 생긴걸로 추측

*/

#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remains;
    for(int i=0 ;i <progresses.size();i++){
        int remain=0;
        int a=100-progresses[i];
         //ceil 함수를 이용해 올림을 구할떄는 변수  a랑 speed의 값이 int이기  double형으로 명시적 형변환을 해줘야함
      //  remain=ceil((double)a/(double)speeds[i]);
        remain=a/speeds[i];
        if(a%speeds[i]!=0){ 
     //테스트 11번 실패 ->a%=spees[i]!=0 -> 연산자 우선순위에 의해 계싼 순서가 !=이 먼저됨
            remain+=1;
        }
  
        remains.push(remain);
    }
     if(remains.empty()){
            answer.push_back(0);
         return answer;
     }
     //q에서 나온값과 그 후에 나온 값들 비교해서 q보다 작거나 같은 값들은 이미 그 전에 개발이 끝남. 그래서 작거나 같은 값들을 카운트
    while(!remains.empty()){
        
        int count=0;
        int q=remains.front();
  
        remains.pop();
        count++;
        
        while(!remains.empty()&&q>=remains.front()){
            count++;
            remains.pop();
        }
        answer.push_back(count);
    }
    return answer;
}

int main(){

    vector<int> answer=solution({96,94},{3,3});
    
    for(auto m : answer){
        cout<< m<<'\n';
    }
}