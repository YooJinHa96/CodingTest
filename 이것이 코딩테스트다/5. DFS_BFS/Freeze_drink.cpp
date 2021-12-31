/*

    음료수 얼려 먹기
    NXM의 크기의 얼음 틀 
    구멍이 뚫어 있는 곳 0, 막혀 있으면 1, 상 하 좌 우 서로 구멍이 뚫어 있는 곳끼리 붙어잇으면 하나로 간주
    아이스 크림 만들수 있는 개수
*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
string Graph[1000];
queue<int> q;
bool visit[10000000]={false};
int N, M;
bool Search( int vertax){
    int x=vertax/M;
    int y=vertax%M;
    if(vertax == -1 ){
        return false;
    }
    if(y>0&&Graph[x][y-1]=='0'&&!visit[vertax-1]){
        visit[vertax-1]=true;
        q.push(vertax-1);
    }
    if(y<M&&Graph[x][y+1]=='0'&&!visit[vertax+1]){
        visit[vertax+1]=true;
        
        q.push(vertax+1);
    }
    if(x>0&&Graph[x-1][y]=='0'&&!visit[vertax-M]){
        visit[vertax-M]=true;
        q.push(vertax-M);
    }
    if(x<N&&Graph[x+1][y]=='0'&&!visit[vertax+M]){
        visit[vertax+M]=true;
        q.push(vertax+M);
    }
    
}
int main(){
   
  
    cin>>N>>M;
    int count=0;
    for(int i=0 ; i<N; i++ ){
            cin>>Graph[i];
    }
    for(int i=0 ; i<N; i++ ){

        for(int k=0;k<M;k++){
            
            if(Graph[i][k]=='0'&&!visit[i*M+k]){
                visit[i*M+k]=true;
                q.push(i*M+k);
                int flag=0;
                while(q.size()!=0){
                    int v=q.front();
                    q.pop();

                    Search(v);
                    
                    flag=1;
                }
                if(flag==1)
                count++;    
            }

        }
    }
    cout<<count<<'\n';

}