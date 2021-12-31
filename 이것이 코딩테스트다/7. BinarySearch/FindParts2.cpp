/*
    부품 찾기
    계수 정렬 이용
*/
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N,M;
    int part[1000000]={0};
    int find_part[100000];
    int num;
    cin>>N;
    for(int i=0 ;i<N;i++){
        cin>>num;
        part[num]=1;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        find_part[i];
    }
    for(int i=0;i<M;i++){
        if(part[find_part[i]]==1){
            cout<<"yes ";
        }
        else{
            cout<<"no ";
        }
    }

}