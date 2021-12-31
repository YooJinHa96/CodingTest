#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int Graph[9][9]={0};
bool visit[9]={false};
void dfs (int vertax){
    cout<<vertax<< ' ';
    visit[vertax]=true;
    for(int i=1 ;i<9;i++){
        if(Graph[vertax][i]==1&&!visit[i]){
            dfs(i);
        }
    }
}
int main(){
   
   Graph[1][2]=1;
   Graph[1][8]=1;
   Graph[1][3]=1;
   Graph[2][1]=1;
   Graph[2][7]=1;
   Graph[3][4]=1;
   Graph[3][1]=1;
   Graph[3][5]=1;
   Graph[4][3]=1;
   Graph[4][5]=1;
   Graph[6][7]=1;
   Graph[7][6]=1;
   Graph[7][2]=1;
   Graph[7][8]=1;
   Graph[8][1]=1;
   Graph[8][7]=1;

   dfs(1);
   cout<<'\n';
}