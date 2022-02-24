#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> money)
{
    int answer = 0;
    int s = money.size()-1 ;
    vector<int> dp1;
    vector<int> dp2;
    dp1.push_back(money[0]);
    dp1.push_back(money[0]);
   
    for(int i=2;i<money.size()-1;i++){
        dp1.push_back(max(dp1[i-1],dp1[i-2]+money[i]));

    }
    dp2.push_back(0);
    dp2.push_back(money[1]);

    for(int i=2;i<money.size();i++){
        dp2.push_back(max(dp2[i-1],dp2[i-2]+money[i]));

    }
    answer=max(*max_element(dp1.begin(),dp1.end()),*max_element(dp2.begin(),dp2.end()));

    return answer;
}

int main()
{
    int answer = solution({91, 90, 5, 7, 5, 7});
    cout << answer << '\n';
}