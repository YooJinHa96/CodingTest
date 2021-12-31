/*
    떡볶이 떡 만들기   


*/
#include <iostream>
#include <algorithm>
using namespace std;

int Tteok[1000000];
int main(){
    int N;
    int M;
    int start,end,mid;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>Tteok[i];
    }
    sort(Tteok,Tteok+N);
    start=0;
    end=Tteok[N-1];
    int sum=0;
    int result=0;
    
    while(start<=end){
        mid=(start+end)/2;
        sum=0;
        for(int i=0; i<N; i++){
    
            if(Tteok[i]>mid){

                sum += Tteok[i] - mid;
            }
    
        }
    
        if(sum >= M){
            result = mid;
            start = mid + 1;
        }
        else if(sum < M){
            end = mid - 1;
        }
    }
    cout<<result<<'\n';

}