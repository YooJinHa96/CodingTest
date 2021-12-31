/*
 왕실의 나이트
 8x8 체스판 나이트가 움직일 수 있는 경우의 수
*/

#include <iostream>
using namespace std;

int main(){
    
    char x;
    int y;
    int knight_x=0,knight_y=0;
    cin>>x>>y;
    int count=0;
    int knight_move[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,-2},{1,-2},{-1,2}};
    knight_x=x-'a';
    knight_y=y-1;
    int dx,dy;
    for(int i= 0 ; i< 8;i++){
        dx=knight_x;
        dy=knight_y;
        dx+=knight_move[i][0];
        dy+=knight_move[i][1];
        if(0<=dx&&dx<8&&0<=dy&&dy<8){
    
            count++;
        }
    }
    cout<<count<<'\n';

}