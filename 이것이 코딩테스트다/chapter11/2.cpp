#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end(),greater<char>());
    long long pro=1;
    for(int i =0 ; i< s.size();i++){
        if(s[i]>'1'){
            pro*=(s[i]-'0');
        }
        else{
            pro+=(s[i]-'0');
        }
    }
    cout<<pro<<'\n';
}