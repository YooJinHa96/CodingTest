#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
char arr[6][6],copy_arr[6][6],solv_arr[6][6];

void check(){
    copy(&copy_arr[0][0],&copy_arr[0][0]+36,&solv_arr[0][0]);
}
void obstacle(int count){
    if(count==3){

    }
    else{

    }
}
int main(){

    cin>>N;
    for(int i =0 ; i < N ; i++){
        for(int j =0 ; j < N ; j ++ )
        {
            cin>>arr[i][j];
        }
    }
}