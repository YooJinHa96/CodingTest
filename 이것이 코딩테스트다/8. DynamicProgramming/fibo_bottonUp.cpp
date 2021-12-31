#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int dp[100]={0};

    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=15;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[15]<<'\n';
}