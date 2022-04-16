#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    int N,a;
    int money=1;
    int index=0;
    int sum_money=0;
    cin>>N;
    vector<int> v;
    for(int i =0 ; i<N;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i =0 ; i <v.size(); i++){

        if(money < v[i])
            break;
        else
        money+=v[i];
    }
    cout<<money<<'\n';
}