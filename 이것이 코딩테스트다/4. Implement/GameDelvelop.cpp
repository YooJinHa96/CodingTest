/*
게임 개발
M*N의 맵, 위치 입력 A, B  상하좌우로 움직일 수 있음, 반시계 방향으로 돌면서 이동, 이동을 마쳤을 때의 횟수, 맵에 육지, 바다 존재
그외 조건 책 참조 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int M,N;
    int map[50][50];
    int visit[50][50]={0};
    int A,B, d,dc=0;
    int count=1;
    int dA,dB,pd;
    //북동남서
    int move_y[4]={-1,0,+1,0};
    int move_x[4]={0,1,0,-1};
    cin >>N>>M;
    cin>>A>>B>>d;
    
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cin>>map[i][k];
        }
    }
    pd =d;//돌기전 방향 
    visit[A][B]=1;
    while(true){
        dA=A;
        dB=B;
        d+=1;
        d%=4;
        dA+=move_x[d];
        dB+=move_y[d];
        dc++;
        if(0<=dA&&dA<M&&0<=dB&&dB<N&&map[dA][dB]==0&&visit[dA][dB]==0){
            visit[dA][dB]=1;     
            A=dA;
            B=dB;
            pd=d;
            dc=0;
     
            count ++;
        }
        else if(dc==4){
            dc=0;
            if(map[(pd+2)%4][(pd+2)%4]==0){
                A+=move_x[(pd+2)%4];
                B+=move_y[(pd+2)%4];
            }
            else{
                break;
            }
        }
   }
   cout<<count<<'\n';          
}

