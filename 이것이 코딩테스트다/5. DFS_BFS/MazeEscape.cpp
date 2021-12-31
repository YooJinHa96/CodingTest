#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int Graph[201][201];
int distance[201][201];
int N,M;
int nx=0,ny=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    int qx,qy;
    q.push(make_pair(x,y));
    

    while(q.size()>0){
        qx=q.front().first;
        qy=q.front().second;
        
        q.pop();
        for(int i=0 ; i< 4;i++){
            nx=qx+dx[i];
            ny=qy+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<M){
                if(Graph[nx][ny]==1){
                    Graph[nx][ny]=Graph[qx][qy]+1;

                    q.push(make_pair(nx,ny));
                }
            }    
        }
    }

}
int main(){
    
    cin>>N>>M;
    string map[201];
    for(int i=0;i<N;i++){
        cin>>map[i];
    }   
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            char c=map[i][k];
            Graph[i][k]=map[i][k]-'0';
        }
    }
    bfs(0,0);
    cout<<Graph[N-1][M-1];
}