#include <iostream>
#include <algorithm>
using namespace std;

int dp[100]={0};


long long fibo(int x){

    if(x==1||x==2){
        dp[x]=1;
        return 1;
    }
    else if(dp[x]!=0){
        return dp[x];
    }
    else{
        dp[x]=fibo(x-1)+fibo(x-2);
        return dp[x];
    }
}

int main(){
    
    int long long result=0;
    result=fibo(15);
    cout<<result<<"\n";
}