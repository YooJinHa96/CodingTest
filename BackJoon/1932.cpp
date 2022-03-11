#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<vector<int>> tri;
    int num;
    vector<vector<int>> dp;
    cin>>N;
    tri.resize(N);
    for(int i=0;i<N;i++){
        for(int k=0;k<=i;k++){
            cin>>num;
            tri[i].push_back(num);
        }
    }
    dp.resize(N);
    dp[0].push_back(tri[0][0]);

    for(int i =1 ; i< N;i++){
        for(int k=0;k<=i;k++){
            if(k==0){
                dp[i].push_back(dp[i-1][0]+tri[i][0]);
            }
            else if(k==i){
                dp[i].push_back(dp[i-1][k-1]+tri[i][k]);
            }
            else{
               
                dp[i].push_back(max(dp[i-1][k-1],dp[i-1][k])+tri[i][k]);
            }
        }
    }
  
    int answer=*max_element(dp[N-1].begin(),dp[N-1].end());
    cout<<answer<<'\n';

}
