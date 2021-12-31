#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
int Graph[9][9]={0};
queue<int> q;
bool visit[9]={false};
void bfs (int vertax){
   visit[vertax]=true;
   q.push(vertax);
   
   while(q.size()!=0){
       int i=q.front();
       cout<<i<<' ';
       q.pop();
       for(int j=1;j<9;j++){
           if(Graph[i][j]&&!visit[j]){
               visit[j]=true;
               q.push(j);
            }
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

   bfs(1);
   cout<<'\n';
}