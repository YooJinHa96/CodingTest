/*
hash로 풀기위해 map 사용 
가지고있는 카드 번호가 key 


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
    map<int,int> mp;
    
    cin>>N;
    for(int i=0; i<N;i++){
        cin>>num;
        mp[num]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        cout<<mp[num]<<' ';
    }
}