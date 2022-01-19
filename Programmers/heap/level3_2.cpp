/*

Programmers Heap 이중 우선순위 큐

명령어에 따라 삽입, 최댓값 삭제, 최소값 삭제 문제

vector를 이용함
삭제명령어 일때 최댓값이면 오름차순으로 정렬해서 제일 뒤에 값 삭제 <- pop_back
삭제명령어가 최솟값으면 내림차순으로 정렬해서 제일 뒤에 값 삭제 

*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;



vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    vector<int> vec;
    for (auto str : operations)
    {
        if (str[0] == 'I')
        {
            string num_s = str.substr(2);
            int num_i = stoi(num_s);
            vec.push_back(num_i);
            //   maxQ.push(num_i);
            // minQ.push(num_i);
        }
        else if (str[0] == 'D')
        {

            if (str[2] == '1')
            {
                 sort(vec.begin(), vec.end());
            }
            else if (str.substr(2) == "-1")
            {

                sort(vec.begin(), vec.end(),greater<int>());
            }
            if(!vec.empty()){
                vec.pop_back();
            }

        }
    }
    if(vec.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        sort(vec.begin(),vec.end());
        answer.push_back(vec[vec.size()-1]);
        answer.push_back(vec[0]);
    }
   
    return answer;
}

int main()
{

    vector<int> answer = solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
    cout << answer[0] << " " << answer[1] << '\n';
}