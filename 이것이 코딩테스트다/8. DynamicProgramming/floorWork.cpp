#include <iostream>


using namespace std;

int main(){
    int dp[1001];
    int N;

    cin>>N;

    dp[0]=0;    
    dp[1]=1;
    dp[2]=3;

    for(int i=3;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2]*2;
    }
    cout<<dp[N]<<'\n';
}
