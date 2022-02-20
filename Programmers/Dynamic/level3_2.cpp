#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    dp[1].push_back(dp[0][0]+triangle[1][0]);
    dp[1].push_back(dp[0][0]+triangle[1][1]);

    for(int i=2;i<triangle.size();i++){
        for(int k=0;k<triangle[i].size();k++)
        {
            if(k==0)
            {
                dp[i].push_back(dp[i-1][k]+triangle[i][k]);
            }
            else if(k==triangle[i].size()-1){
        
                dp[i].push_back(dp[i-1][k-1]+triangle[i][k]);
            }
            else{
                dp[i].push_back(max(dp[i-1][k-1],dp[i-1][k])+triangle[i][k]);
            }
        }
    }

    answer=*max_element(dp[triangle.size()-1].begin(),dp[triangle.size()-1].end());

    return answer;
}

int main(){
    int answer=solution({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}});
    cout<<answer<<'\n';
}