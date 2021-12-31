/*
 부품찾기
    이진탐색이용
*/


#include <iostream>
#include <algorithm>
using namespace std;
int part[1000000];
int find_part[100000];

int main(){
    int N,M;
    
    int start, end, mid;
    int target,flag;

    std::cin>>N;
    for(int i=0 ;i<N;i++){
       std:: cin>>part[i];
    
    }
    
    sort(part,part+N);

    std:: cin>>M;
    
    for(int i=0;i<M;i++){
      std::  cin>>find_part[i];
    }

    for(int i=0;i<M;i++){   
        start = 0;
        end = N-1;

        target=find_part[i];
        flag=0;
        while(start<=end){
            
            mid=(start+end)/2;
            if(part[mid]==target){
                flag=1;
                break;
            }
            else if(part[mid]>target){
                end = mid - 1 ;
            }
            else{
                start = mid + 1 ;
            }
        }   
        if(flag==1)
        {
            cout<<"yes ";
        }
        else{
            cout<<"no ";
        }
    }
    
}
