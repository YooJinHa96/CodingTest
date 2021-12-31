#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int count =0;
    int N,K;
    cin>>N>>K;

    while (true){
        if(N==1)
            break;
        if(N%K==0)
        {
            N/=K;
            count++;
        }
        else{
            N-=1;
            count++;
        }
    }
    cout<<count<<"\n";
}