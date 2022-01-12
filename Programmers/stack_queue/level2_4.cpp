/*

Programmers  주식 가격

위치랑 가격을 stack에 넣어서 -> 뒤에서 부터 확인 해 갔음 
이유 : 처음 생각은 뒤에서부터 보면서 최솟 값을 찾아 그것보다 작은 것들은 다 가격이 떨어지지 않는 것으로 판단하면서 쉽게 풀수 있을 것이라 생각함.
문제는 떨어지는 가격을 하나 찾는다고 해도 그 이후에 무슨 값이 나올 지 몰라 최솟 값을 통해 모든 주시가격들의 하락점을 제대로 찾을 수가 없었다.
그래서 이중 반복을 통해 stack에서 꺼낸 위치부터 주시가격의 끝까지 비교하는식으로 진행

*/

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
    stack<pair<int, int>> stock;

    for (int i = 0; i < prices.size(); i++)
    {
        stock.push(make_pair(i, prices[i]));
    }

    while (!stock.empty())
    {
        //최소 값보다 작은 가격은 가격이 떨어지는 점이 없다는 것을 의미 하기 때문에 전체 길이에서 현위치를 빼서 계산
        if (min_value >= stock.top().second)
        {
            answer.push_back(prices.size() - 1 - stock.top().first);
            min_index = stock.top().first;
            min_value = stock.top().second;
            stock.pop();
        }
        else
        {
            //현 시점부터 끝까지 하락점을 하나 찾을때 까지 반복
            for (int i = stock.top().first; i < prices.size(); i++)
            {
                if(stock.top().second>prices[i]){
                    answer.push_back(i-stock.top().first);
                    stock.pop();
                    break;
                }
            }
        }
    }
    //stack 때문에 뒤에서부터 진행되서 reverse함수를 이용해 순서를 뒤집음
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> ans = solution({7, 8, 4, 3, 2, 5, 2});

    for (auto a : ans)
    {
        cout << a << ' ';
    }
}