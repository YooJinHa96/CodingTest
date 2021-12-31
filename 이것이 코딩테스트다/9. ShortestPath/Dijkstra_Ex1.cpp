#include <iostream>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int main(){

    int N,M;
    int start;
    bool* visit;
    int **graph;
    int *distance;
    cin>>N>>M;

    cin>>start;
    
    
    visit=new bool[N+1];

    fill(visit,visit+(N+1),false);
    graph=new int*[N+1];
    distance=new int[N+1];
    fill(distance,distance+(N+1),INF);

    for(int i=0; i<N+1;i++){
        graph[i]=new int[N];
        
        for(int k=0;k<N+1;k++){
            graph[i][k]=0;
        }
    }
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c; 
        graph[a][b]=c;      
    }

    distance[start]=0;
    visit[start]=true;
    int min_val=INF;

    for(int i=1;i<N+1;i++){

        if(graph[start][i]!=0)
        distance[i]=graph[start][i];
    
    }

    for(int i=1;i<N+1;i++){       
        min_val=INF;
        for(int j=1;j<N+1;j++){  
         
            if(distance[j]<min_val&&!visit[j]){
         
                min_val=distance[j];
                start=j;
                visit[start]=true;
         
            }
        }
        for(int i=1;i<N+1;i++){
            if(graph[start][i]!=0)
            distance[i]=min(distance[i],distance[start]+graph[start][i]);
        }
    }
    for(int i=1 ;i<N+1;i++){
        cout<<distance[i]<<'\n';
    }


}