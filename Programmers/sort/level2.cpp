#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}
bool compare(string s1,string s2){
    if(s1[0]!=s2[0]){
        return s1>s2;
    }
    else if(s1.length()!=s2.length()){
        if(s1.length()<s2.length()){
            for(int i=1;i<s2.length();i++){
                    if(s1[s1.size()-1]<s2[i]){
                        return false;
                    }
                    else if(s1[s1.size()-1]>s2[i]){
                        return true;
                    }
            }
            return true;
        }
        else if(s1.length()>s2.length()){
            for(int i=1;i<s1.length();i++){
                    if(s1[i]>s2[s2.size()-1]){
                        return true;
                    }
                    else if(s1[i]<s2[s2.size()-1]){
                        return false;
                    }
            }
            return false;
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
    
    for(auto a : answer){
        if(a!='0'){
            return answer;
        }

    }
    return "0";
}

int main(){
    //string answer=solution({3,31,343,323,32,332,301,1000, 300,30,34, 100,10,5, 9,01});
    string answer=solution({123,12,132,13,32,123});
    //string answer=solution({1,0,1,0});
 cout<<answer<<'\n';
    
}