#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
string answer = "";
bool check_balnce(string u)
{

    stack<char> st;

    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(')
        {
            st.push(u[i]);
        }
        else if (u[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
string balance_string(string p)
{

    string u, v;
    queue<char> q;
    vector<char> left;
    vector<char> right;
    string ans;

    if (p == "")
    {
        return p;
    }
    else
    {
        for (int i = 0; i < p.size(); i++)
        {
            q.push(p[i]);
            if (p[i] == '(')
            {
                left.push_back(p[i]);
            }
            else if (p[i] == ')')
            {
                right.push_back(p[i]);
            }
            if (left.size() == right.size())
            {
                while (!q.empty())
                {
                    u += q.front();
                    q.pop();
                }

                for (int j = i + 1; j < p.size(); j++)
                {
                    v += p[j];
                }

                break;
            }
        }
        if (check_balnce(u))
        {

            ans += u;

            ans += balance_string(v);
        }
        else
        {

            string a = "(";
            a += balance_string(v);
            a += (")");
            string b;
            for (int k = 0; k < u.size(); k++)
            {
                if (k != 0 && k != u.size() - 1)
                {
                    if (u[k] == '(')
                    {
                        b += ')';
                    }
                    else
                    {
                        b += '(';
                    }
                }
            }
            a += b;
            return a;
        }
    }

    return ans;
}

string solution(string p)
{

    answer = balance_string(p);
    return answer;
}
int main()
{
    // string answer=solution("(()())()");
    // string answer=solution(")(");
    string answer = solution("()))((()");
    cout << answer << "\n";
}
