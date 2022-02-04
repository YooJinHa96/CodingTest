#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// copy.erase(find(copy.begin(),copy.end(),str[k])); //"17" 11 중복 제거  01 011
string solution(string number, int k)
{
    string answer = "";
    string copy = number;
    string copy_sort;
    deque<int> dq;
    int count = 0;
    int index = 0;
    int f_count = 0;
    bool check=false;
    copy_sort = number;
    //dq.push_back(number[0]);
    //int index=0;
    while (count < k)
    {
        for(int i=0;i<number.size()-1;i++){
            if(number[i]<number[i+1]){
                number.erase(number.begin()+i);
                count++;
               // i--;
                check=true;
                break;
            }
        }
        if(!check){
            number.erase(number.end()-(k-count),number.end());
            break;
        }
    }

    answer = number;
   
    return answer;
}
int main()
{
    string num="777777777777";
    string answer = solution(num, 4);
    //string answer = solution("777784", 5);

    cout << answer << '\n';
}