#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int min_index = prices.size() - 1;
    int min_value = prices[prices.size() - 1];
    stack<pair<int, int>> st;
    int count = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        st.push(make_pair(i, prices[i]));
    }

    while (!st.empty())
    {

        if (min_value >= st.top().second)
        {
            answer.push_back(prices.size() - 1 - st.top().first);

            min_index = st.top().first;
            min_value = st.top().second;
            st.pop();
        }
        else
        {
            answer.push_back(min_index - st.top().first);
            st.pop();
        }
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main(){
    vector<int> ans=solution({7,8,4,3,2,5,2});
    
    for (auto a : ans){
        cout<< a<< ' ';
    }
}