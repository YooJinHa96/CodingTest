#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int num;
    int N,C;
    int answer;
    vector<int> v;
    cin>>N>>C;
    for(int i =0 ;i<N;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    answer=0;
    int left=0;
    int right=v[v.size()-1];
    int mid =(left+right)/2;
    
    while(left<=right){
        int house=0;
        mid =(left+right)/2;
        int cnt=1;

        for(int i=1 ;i < N;i++){
            if(v[i]-v[house]>=mid){
                cnt++;
                house=i;
            }
        }
        if(cnt>=C){
            answer=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<answer<<'\n';   

}