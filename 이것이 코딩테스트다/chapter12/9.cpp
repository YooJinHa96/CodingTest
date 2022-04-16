#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.size();
    string sub;
    for(int i = 1 ; i<=s.length()/2;i++){
        sub=s.substr(0,i);
        string temp="";
        int cnt =1 ;
        for(int k =i ; k<s.size();k+=i){
            if(sub==s.substr(k,i))cnt++;
            else{
                if(cnt>1)temp=to_string(cnt);
                temp+=sub;
                sub=s.substr(k,i);
                cnt=1;
            }
        }
        if(cnt>1)temp=to_string(cnt);
        temp+=sub;
        answer=min(answer,(int)temp.length());
    }
    return answer;
}