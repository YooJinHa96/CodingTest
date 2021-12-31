#include <iostream>
#include <algorithm>

using namespace std;
#define INF (int)1e9

int main(){
    int graph[101][101];
    int N,M;
    int a,b;
    int X,K;
    cin>>N>>M;
    
    for(int i=0 ;i<N+1;i++){
        fill(graph[i],graph[i]+(N+1),INF);
    }
    
 //자기 자신에서 자신으로 가는 비용 =0
    for(int i=0; i<N+1;i++){
        for(int k=0;k<N+1;k++){
            if(i==k){
                graph[i][k]=0;
            }
        }
    }

    for(int i=1;i<=M;i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    cin>>X>>K;

   for(int i=1;i<=N;i++){
        for(int k=1;k<=N;k++){

            for(int q=1;q<=N;q++)
            {
                graph[k][q]=min(graph[k][q],graph[k][i]+graph[i][q]);
            }
        }

    }
    int sum=graph[1][K]+graph[K][X];
    if(sum<INF){
        cout<<graph[1][K]+graph[K][X]<<'\n';
    }
    else{
        cout<<"-1"<<'\n';
    }
}