#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin>>N;
    string num=to_string(N);

    int left=0;
    int right =0;

    for(int i =0 ; i<num.length()/2;i++){
        left+=num[i]-'0';
    }    
    for(int i = num.length()/2;i<num.length();i++){
        right+=num[i]-'0';
    }
    if(left==right){
        cout<<"LUCKY"<<'\n';
    }
    else{
        cout<<"READY"<<'\n';
    }
    
}