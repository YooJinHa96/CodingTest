#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }
    for (int i = 0; i < lost.size(); i++)
    {
        mp[ lost[i] ]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        mp[ reserve[i] ]++;
    }

    for (int i = 1; i <= n; i++)
    {

        if (mp[i] == 0)
        {
            if (i - 1 != 0 && mp[ i - 1 ] > 1)
            {
                mp[ i - 1 ]--;
                mp[i]++;
            }
            else if(i+1 != n+1 && mp [ i + 1 ]>1){
                mp[ i + 1 ]--;
                mp[ i ]++;
            }
        }
    }
    for(auto m : mp){
        if(m.second>0)
        answer++;
    }
    return answer;
}