#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string s1,string s2){
    if(s1[0]!=s2[0]){
        return s1>s2;
    }
    else if(s1.length()!=s2.length()){
        
        if(s1.length()<s2.length()){
            for(int i=1;i<s2.length();i++){
                    if(s1[0]<s2[i]){
                        return s1>s2;
                    }
                    else if(s1[0]>s2[i]){
                        return s1<s2;
                    }
            }
        }
        else if(s1.length()>s2.length()){
            for(int i=1;i<s1.length();i++){
                    if(s2[0]<s1[i]){
                        return s1>s2;
                    }
                    else if(s2[0]>s1[i]){
                        return s1<s2;
                    }
            }
        }
    }
    
    else{ // s1.lengh==s2.lengh 
        return s1>s2;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> string_numbers;

    for(auto num : numbers)
        string_numbers.push_back(to_string(num));

    sort(string_numbers.begin(),string_numbers.end(),compare);

    for(auto str: string_numbers)
    cout<<str<<'\n';

    for(auto str : string_numbers)
         answer+=str;
    return answer;
}
int main(){
    string answer=solution({3,31,320, 30, 34, 5, 9});
    cout<<answer<<'\n';
}