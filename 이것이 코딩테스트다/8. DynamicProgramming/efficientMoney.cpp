/*
효율적인 화폐 구성
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N,M;
    int money[10001];
    int dp[10001];
    cin>>N>>M;
    int num=0;

    
    fill(dp,dp+10001,10001);
    dp[0]=0;
    for(int i=0;i<N;i++){
        cin>>num;
        dp[num]=1;
    }

    for(int i=2;i<=M;i++){
        
        for(int k=1;k<=i/2;k++){
            dp[i]=min(dp[i],dp[k]+dp[i-k]);
            
        }
    }
    
    if(dp[M]>=10001){
        cout<<-1<<'\n';
    }
    else{
        cout<<dp[M]<<'\n';
    }
    


}