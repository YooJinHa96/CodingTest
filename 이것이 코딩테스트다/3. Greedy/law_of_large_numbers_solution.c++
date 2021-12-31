#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare (int a, int b){
    return a>b;
}
int main ()
{
    int N, M ,K;
    int num;
    vector<int> data;
    cin>>N>>M>>K;

    for (int i= 0 ; i<N;i++){
        cin>>num;
        data.push_back(num);
    }
    sort(data.begin(),data.end(), compare);
    
    int answer =0 ;
    
    int count = 0 ; // 큰 수가 더해지는 횟수 계산
    count = M /(K+1)*K;
    count+= M&(K+1);// 나누어 떨어 지지 않았을 때 

    answer+= count * data[0];// 가장 큰 수 더하기
    answer+=(M-count)*data[1];//두번 째 큰 수 더하기
    cout<< answer << "\n";
}