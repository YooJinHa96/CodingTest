/*
Programmers Heap 더 맵게

스코빌 지수가 낮은 두개를 합쳐서 k이사으이 스코빌 지수만들기

우선순위큐를 이용해서 앞에 두개를 꺼내 합치고 다시 넣고를 반복해서 횟구 구함
*/

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int, vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    int front=pq.top();
    int mix_scoville=0;
    pq.pop();
    int count =0;
    while(!pq.empty()){
        mix_scoville=front+(pq.top()*2);
        pq.pop();
        count++;
        pq.push(mix_scoville);
        if(pq.top()>=K){
            answer=count;
           break;
        }
        front=pq.top();
        pq.pop();
        
    }
    
    return answer;
}

int main(){
    int answer=solution({1, 2, 3, 9, 10, 12},1000);
    cout<<answer<<'\n';
}