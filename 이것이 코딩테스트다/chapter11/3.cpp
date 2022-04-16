#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    map<char, int> mp;
    int count =0 ;
    char c;
    cin>>s;
    c=s.at(0);
    for(int i =1 ; i<s.size();i++){
        if(c!=s[i]){
            mp[c]++;
            c=s[i];
        }
    }
    int answer=min(mp['0'],mp['1']);
    cout<<answer<<'\n';
}