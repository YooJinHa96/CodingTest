#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int x,int y){
    return x>y;

}

int main(){
    int N,K;
    int A[100000];
    int B[100000];
    int sum=0;
    
    cin>>N>>K;
    for (int i=0;i<N;i++){
        cin>>A[i];
    }
    for (int i=0;i<N;i++){
        cin>>B[i];
    }
    sort(A,A+N);
    sort(B,B+N,comp);

    for(int i=0;i<K;i++){
        if(A[i]<B[i]){
            int temp=A[i];
            A[i]=B[i];
            B[i]=temp;
        }
    }
    for(int i=0;i<N;i++){
        sum+=A[i];

    }
    
    cout<<sum<<'\n';
}