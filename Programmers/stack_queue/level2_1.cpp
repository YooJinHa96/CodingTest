/*

스택/ 큐 -> level 2 -> 기능개발
작업 진도랑 개발 속도가 적힌 정수 배열이 주어질 때 각 배포마다 몇개 기능이 배포되는지 구하기

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