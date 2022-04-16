#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string str;
    cin>>str;
    string answer="";
    int sum=0;
    sort(str.begin(),str.end());

    for(int i =0 ;i <str.length();i++){
        if(isalpha(str[i])==0){
            sum+=str[i]-'0';
        }
        else{
            answer+=str[i];
        }
    }
    if(sum!=0)
    answer+=to_string(sum);
    cout<<answer<<'\n';
}