#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define Jinha 10000000007
int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    int dp[101][101];
    
    for(int i=0 ; i< m;i++){
        for(int k=0;k<n;k++){
            dp[i][k]=1;
        }
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;

    for (auto p : puddles)
    {

        dp[p[0] - 1][p[1] - 1] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (dp[i][k] != 0)
            {
                if (i == 0 && k == 0)
                    continue;
                if (i == 0)
                {
                    if(dp[i][k-1]!=0)
                    dp[i][k] = dp[i][k - 1];
              
                }
                else if (k == 0)
                {
                    if(dp[i-1][k]!=0)
                    dp[i][k] = dp[i - 1][k];

                }
                else
                {
                    dp[i][k] = (dp[i - 1][k] + dp[i][k - 1]) % Jinha;
                   
                }
            }
        }
    }
    
    answer=dp[m-1][n-1];
    return answer;
}

int main(){

    int answer=solution(4,3,{{2,2}});
    cout<<answer<<'\n';
}