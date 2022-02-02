#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
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
    sort(numbers.begin(), numbers.end(),greater<char>());
    set<int> st;
    vector<bool> visit;
    visit.resize(stoi(numbers),false);
    sort(numbers.begin(), numbers.end());
    string copy = numbers;
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            string s = numbers.substr(0, i);
            int num = stoi(s);
           
            if (sosu(num))
            {
                st.insert(num);
                /*
                if(!visit[num]){
                    cout<<num<<'\n';
                    visit[num]=true;
                    answer++;
                }
                */
            }
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    answer=st.size();
    return answer;
}

int main()
{
    int answer = solution("17");
    cout << answer << '\n';
}
