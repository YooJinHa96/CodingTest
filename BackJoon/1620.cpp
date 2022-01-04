/*
hash -> map 사용


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int N, M;
    int num;
    string name;
    map<string,int> name_mp;
    map<string, string> num_mp;
    
    cin>>N>>M;
    for(int i=0;i <N;i++){
        cin>>name;
        name_mp[name]=i+1;
        num_mp[to_string(i+1)]=name;
    }
    for(int i=0;i<M;i++){
        string str;
        cin>>str;
        if(isdigit(str.at(0))==0){
            cout<<name_mp[str]<<'\n';
        }
        else{
        cout<<num_mp[str]<<'\n';
        }
    }
}