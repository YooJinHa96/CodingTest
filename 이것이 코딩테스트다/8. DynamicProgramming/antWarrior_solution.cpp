#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int dp[101]={0};
    int food[101]={0};
    int N;

    std::cin>>N;
    for(int i=1;i<=N;i++){
        std::cin>>food[i];
    }
    dp[1]=food[1];
    dp[2]=max(food[1],food[2]);

    for(int i=3;i<=N;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+food[i]);
    }
    cout<<dp[N]<<'\n';

}