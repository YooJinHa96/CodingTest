#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    map<char,int> mp;

    string number;
    cin>>number;
    for(auto c : number){
        if(c=='6'){
            if(mp[c]>mp['9']){
                c='9';
            }
        }
        else if (c=='9'){
            if(mp[c]>mp['6']){
                c='6';
            }
        }
        mp[c]++;
        
    }
  
    int count=0;
    for(auto m : mp){
        count=max(count, m.second);
    }
    cout<< count<<'\n';
}