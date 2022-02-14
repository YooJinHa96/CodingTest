#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int len = name.length();
    int start_index, end_index = 0;
    int A_len = 0;
    int A=0;
    start_index = 0;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != 'A')
        {
            if (i != 0 && A_len < A)
            {
                A_len = A;
                start_index = i - A - 1;
                end_index = i;
            }
            A = 0;
        }
        else
        {
           A++;
        }
    }
    if (A_len < A)
    { //끝까지 A일 떄
        A_len = A;
        start_index = len - A - 1;
        end_index = len;
    }
    if (start_index == -1)
        start_index = 0;
    int s_index = start_index;
    if (s_index != 0)
    {
        for (int i = start_index; i > 0; i--)
        {
            if (name[i] != 'A')
            {
                s_index = i;
            }
        }
    }
    int e_index = end_index;
    if (e_index != len)
    {
        for (int i = end_index; i < name.length(); i++)
        {
            if (name[i] != 'A')
            {
                e_index = i;
            }
        }
    }
 
    if (A_len != 0)
        answer = min(min(e_index, start_index * 2 + len - end_index), min((len - end_index) * 2 + start_index, len - s_index));
    else
        answer = len - 1;
        
    for (int i = 0; i < len; i++)
    {
        if (name[i] <= 'N') 
            answer += name[i] - 'A';
        else  
            answer += 'Z' - name[i] + 1;
    }
    return answer;
}
