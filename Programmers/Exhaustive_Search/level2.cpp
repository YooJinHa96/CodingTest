#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool sosu(int num)
{
    if (num < 2)
        return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
        if (num % i == 0)
            return false;
    return true;
}
int solution(string numbers)
{
    int answer = 0;
    bool flag = true;
    int count = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());
    int max = stoi(numbers);
    for (int i = 1; i <= max; i++)
    {
        flag = true;
        string str = to_string(i);
        string copy = numbers;

        for (int k = 0; k < str.length(); k++)
        {
             
            if (copy.find(str[k]) == string::npos)
            {

                flag = false;
                break;
            }
            else
            {
              
                copy.erase(find(copy.begin(),copy.end(),str[k]));
                
            }
        }
        if (flag)
        {
            if (sosu(i))
            {
                cout << i << '\n';
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    int answer = solution("101");
    cout << answer << '\n';
}
