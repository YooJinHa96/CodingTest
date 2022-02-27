#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

int same_count(string str, string str2)
{
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str2[i])
        {
            count++;
        }
    }
    return count;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    queue<pair<string, int>> q;
    map<string, bool> visit;
    for (auto word : words)
    {
        visit[word] = false;
    }

    for (auto s : words)
    {
        if (same_count(begin, s) == 1)
        {
            q.push(make_pair(s, 1));

            visit[s] = true;
            if (s == target)
            {
                return 1;
            }
        }
    }
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            string str = q.front().first;
            int c = q.front().second;
            q.pop();
            for (auto s : words)
            {
                if (!visit[s])
                {
                    if (same_count(s, str) == 1)
                    {
                        if (s == target)
                        {
                            return ++c;
                        }
                        else
                        {
                            q.push(make_pair(s, ++c));
                            visit[s] = true;
                        }
                    }
                }
            }
        }
    }

    return answer;
}