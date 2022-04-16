#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){

    return a.second<b.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int,int>> food;
    long long sum = 0;
    for(int i =0 ; i < food_times.size();i++){
        food.push_back({food_times[i],i+1});
    }
    sort(food.begin(),food.end());
    int n = food_times.size();
    int pretime = 0 ; 
    for(vector<pair<int,int>> :: iterator it = food.begin() ; it !=food.end(); ++it, --n){
        long long spend = (long long)(it ->first-pretime)*n;
        if(spend==0)continue;
        if(spend <= k){
            k-=spend;
            pretime = it->first;
        }
        else{
            k %=n;
            sort(it, food.end(),cmp);
            return (it +k)->second;
        }
    }
    
    return -1;
}
int main(){
    int answer= solution({3,1,2},5);;
}