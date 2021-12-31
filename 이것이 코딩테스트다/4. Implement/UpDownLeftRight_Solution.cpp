/*
공간의 크기 0<N<100, 움직임 계획 수 < 100
위치 파악  
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    
    int N;
    int current_X=1;
    int current_Y=1;
    int nx=1, ny=1;
    int dx[4]={0,0,-1,+1};
    int dy[4]={-1,+1,0,0};
    char move_types[4]={'L','R','U','D'};
    string move_plans; 
    cin >> N;
    cin.ignore();
    getline(cin, move_plans);
    
    move_plans.erase(remove(move_plans.begin(),move_plans.end(),' '),move_plans.end());
    
    for(int i=0; i< move_plans.length();i++){
        for(int k=0 ; k<4;k++){
            if(move_plans[i]==move_types[k]){
                nx=current_X+dx[k];
                ny=current_Y+dy[k];
            }
        }
        /*
        if(nx<1||nx>N||ny<1||ny>N){
            continue;    
        }
        current_X=nx;
        current_Y=ny;
        */
       if(1<=nx&&nx<=N&&1<=ny&&ny<=N){
           current_X=nx;
           current_Y=ny;
       }       
    }
    cout<<current_X<<' '<<current_Y<<'\n';   
    
}