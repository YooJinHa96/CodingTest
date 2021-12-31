#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int count =0;
    int N,K;
    cin>>N>>K;
    int target=0;

    while (true){
        // N==K 로 나누어 떨어 질 때 까지 1씩 빼기
        target=(N/K)*K; // -> N이 K로 나누어 떨어지지 않을 때 K로 나누어 떨어지는 수 중 N과 가장 가까운 수를 찾는 방법
        count+=(N-target); // 1을 빼는 연산의 횟수
        N=target; //N = 나누어떨이지는 수
        //N이 K보다 작을 때 반복문 탈출 -> 더 이상 나눌 것이 없음
        if( N<K){
            break;
        }
        // K로 나누기
        //N을 k로 한번더 나누기 때문에 count 추가
        count+=1;
        N/=K;

    }
    
    count+=(N-1);
    cout<<count<<"\n";
}