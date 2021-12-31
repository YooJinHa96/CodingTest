#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,target;
    int num[100];
    int start,end,mid;

    cin>>N>>target;

    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    start=0;
    end=N-1;

    while (start<=end){
        mid=(start+end)/2;

        if(num[mid]==target){
            cout<<mid+1<<'\n';
            break;
        }    
        else if(num[mid]>target){
            end= mid -1;
        }
        else
        {
            start=mid+1;
        }
    }

}