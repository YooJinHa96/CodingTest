#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// copy.erase(find(copy.begin(),copy.end(),str[k])); //"17" 11 중복 제거  01 011
string solution(string number, int k)
{
    string answer = "";
    string copy = number;
    int count = 0;
    int index = 0;
    int f_count=0;
    while (count < k)
    {   
        char c=number[0];
        f_count=0;
        for(int i=0; i< number.size();i++){
            if(c==number[i]){
                f_count++;
            }
        }
        if(f_count==number.size()){
            number.pop_back();
            count++;
        }
        if(number.size() == 2){
            sort(number.begin(),number.end(),greater<char>());
            number.pop_back();

            
            break;
        }
        if (index - 1 != -1 && number[index - 1] < number[index])
        {
            cout << "before " << number << ' ';
            number.erase(find(number.begin(), number.end(), number[index - 1]));
            count++;
            cout << "after " << number << '\n';
        }
        else if (index + 1 != number.size() && number[index + 1] < number[index])
        {
            cout << "before " << number << ' ';
            number.erase(find(number.begin(), number.end(), number[index + 1]));
            count++;
            index++;
            cout << "after " << number << '\n';
            if (index == number.size())
            {
                
                index = 0;
            }
        }
        else
        {
            index++;
            if (index == number.size())
            {
                
                index = 0;
            }
        }
    }

    answer = number;
    return answer;
}
int main()
{
   string answer = solution("77764", 4);
    //string answer = solution("777784", 5);
    
    
    cout<<answer<<'\n';
}