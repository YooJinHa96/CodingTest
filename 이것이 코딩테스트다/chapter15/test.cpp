#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    vector<string> words={"frodo","front","frost","frozen","frame","kakao"};
    vector<string> queries={"fro??", "???ro", "fr???", "fro???", "pro?"};

    string str;
 
    sort(words.begin(),words.end());
    for(auto s : words){
        cout<<s<<' ';
    }
    
}