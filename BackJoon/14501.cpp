#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
int main(){
    int N;
    vector<pair<int,int>> dp;
    vector<pair<int,int>> A;

    cin>> N;
    dp.resize(N+1);
    int num1,num2;
    for(int i=0 ; i <N;i++){
        cin>>num1>>num2;
        A.push_back(make_pair(num1,num2));
    }
    if(A[0].first <N){
        dp[0].first=A[0].first;
        dp[0].second=A[0].second;
    }
    for(int i = 1 ;i <N;i++){
            for(int k = 0; k<i;k++){
                if(dp[k].first + k <= i){
                    dp[i].second=max(dp[k].second,dp[i].second);
                }
            }
            if(i+A[i].first <=N){
                dp[i].first=A[i].first;
                dp[i].second+=A[i].second;
            }
    }
  
    sort(dp.begin(),dp.end(),cmp);
    int answer=dp[0].second;   
    cout<< answer<<'\n';
}