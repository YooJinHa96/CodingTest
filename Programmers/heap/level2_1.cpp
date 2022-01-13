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