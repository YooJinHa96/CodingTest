/*

 플로이디 워셜 알고리즘 예시 코드

*/

#include <iostream>
#include <algorithm>

#define INF (int)1e9

using namespace std;

int graph[100][100];

int main(){
    int N,M;

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

    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        graph[a][b]=c;
    }

    for(int i=1;i<=N;i++){
        
        for(int k=1;k<=N;k++){

            for(int q=1;q<=N;q++)
            {
                graph[k][q]=min(graph[k][q],graph[k][i]+graph[i][q]);
            }
        }

    }

    for(int i=1;i<=N;i++){
        
        for(int k=1;k<=N;k++){

            if(graph[i][k]!=INF)
            {
                cout<<graph[i][k]<<' ';
            }

        }
        cout<<'\n';

    }

}