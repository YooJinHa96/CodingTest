/*
    시각 입력수 N -> N시 59분 59초까지 3이 나오는 횟수
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){

    int N;
    int result=1;
    int count =0 ;
    cin >>N;
    for( int i=0 ;i < N+1;i++){
        for (int j=0;j<60;j++){
            for(int k=0 ;k<60;k++){
                if((i % 10 == 3 || i / 10 == 3) || (j % 10 == 3 || j / 10 == 3) || (k % 10 == 3 || k / 10 == 3 ))
           
                count++;
            }
        }
    }
    cout<<count<<'\n';

}

