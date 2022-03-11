#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> dp;

    dp.push_back(0);//0
    dp.push_back(1);//1
    

    for(int i=2; i<=N;i++){
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    cout<<dp[N]<<'\n';

}