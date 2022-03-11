#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main(){

    long long sum=0;
    int N;
    double avg=0;
    int center;
    int range;
    map<int,int> mp;
    vector<int> v;
  
    cin>>N;
    int num;
    for(int i = 0 ;i<N;i++){
        cin>>num;
        sum+=num;
        v.push_back(num);
        mp[num]++;
    }
    int count=0;
    sort(v.begin(),v.end());
    vector<pair<int,int>> vec(mp.begin(),mp.end());
    sort(vec.begin(),vec.end(),cmp);
    avg=round((double)sum/N);
    center=v[(v.size()-1)/2];
  
    
    if(vec[0].second==vec[1].second)
    count=vec[1].first;
    else{
        count=vec[0].first;
    }
    
    range=v[v.size()-1]-v[0];
    if(avg==-0){
        avg=0;
    }
    cout<<avg<<'\n';
    cout<<center<<'\n';
    cout<<count<<'\n';
    cout<<range<<'\n';
}