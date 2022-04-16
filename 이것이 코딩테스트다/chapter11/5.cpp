#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int answer=0;
    int N, M;
    map<int,int> mp;
    vector<int> ball;
    cin>>N>>M;
    int a;
    for(int i =0 ; i <N;i++)
    {
        cin>>a;
        ball.push_back(a);
        mp[a]++;
    }
    int sum =0 ; 
    for(int i =1 ; i<=N;i++){
        sum+=N-(i);
        mp[ball[i-1]]--;

        if(mp[ball[i-1]]!=0){
            sum-=1;
        }
      
    } 

    cout<<sum<<'\n';
    return 0;
}   