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
    dp[2]=food[2];
    dp[3]=food[1]+food[3];

    for(int i=4;i<=N;i++)
    {
        dp[i]=max(dp[i-2],dp[i-3])+food[i];
    }
    int result;
    result=max(dp[N],dp[N-1]);
    cout<<result<<'\n';

}