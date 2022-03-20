#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin>>N;
    int answer;
    for(int i =1 ; i<=N;i++){
        int num = i;
        int sum=0;
        while(1){
            sum+=(num%10);
            num=num/10;
            if(num<10){
                sum+=num;
                break;
            }
        }
        sum+=i;
        if(sum==N){
            answer=i;
            break;

        }
        else if(sum>N){
            answer =0 ;
        }
    }
    cout<<answer<<'\n';
}