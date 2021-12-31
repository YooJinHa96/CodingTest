#include <iostream>
#include <algorithm>
using namespace std;

int dp[30000]={0};
int main(){
    int X;
    cin>>X;

    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=X;i++){
        dp[i]=dp[i-1]+1;
        
        if(i%2==0){
            dp[i]=min(dp[i],dp[i/2]+1);    
        }
        if(i%3==0){
            dp[i]=min(dp[i],dp[i/3]+1);
        }
        if(i%5==0){
            dp[i]=min(dp[i],dp[i/5]+1);
        }
    }
    
    cout<<dp[X]<<'\n';

}