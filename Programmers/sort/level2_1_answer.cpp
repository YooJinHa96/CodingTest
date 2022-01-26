/*
    Programmers sort level2_1_answer
    
    문자열을 이용한 정렬 이용
    하나씩 비교하는 것이 아니라  문자열을 앞뒤로 합쳐서 비교 진행

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool compare(string s1, string s2)
{
    if(s1+s2>s2+s1){
        return true;
    }
    else{
        return false;
    }
}
string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> string_numbers;

    for (auto num : numbers)
        string_numbers.push_back(to_string(num));

    sort(string_numbers.begin(), string_numbers.end(), compare);

    for (auto str : string_numbers)
        cout << str << '\n';

    for (auto str : string_numbers)
        answer += str;

    for (auto a : answer)
    {
        if (a != '0')
        {
            return answer;
        }
    }
    return "0";
}

int main()
{
    //string answer=solution({31,343,323,32,332,301,1000, 300,30,35,330,3, 100,10,5, 9,01});
    string answer = solution({45, 454, 123, 12, 132, 13, 32, 43, 434, 4, 435, 433, 432, 453, 45, 1000, 10, 100, 1, 330, 3, 440});
    //string answer=solution({1,0,1,0});
    cout << answer << '\n';
}
