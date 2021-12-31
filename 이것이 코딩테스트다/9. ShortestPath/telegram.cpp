#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define INF (int)1e9

int main(){
    int time[30001];
    bool visit[30001];
    int N,M,C;
    vector<vector<pair<int,int>>> graph;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int start;
    int X,Y,Z;
    cin>>N>>M>>C;
     
    for(int i=0;i<N+1;i++){   
        vector<pair<int,int>> p;
        graph.push_back(p);
    }
    
      for(int i=0;i<M;i++){
        cin>>X>>Y>>Z; 
        graph[X].push_back(make_pair(Y,Z));
    }

    fill(visit,visit+(N+1),false);
    fill(time,time+(N+1),INF);

    start=C;
    time[start] = 0 ;

    q.push({0,start});
    while(!q.empty()){

        int t=q.top().first;
        int now=q.top().second;
       
        q.pop();

        if(!visit[now]){

            visit[now]=true;
            
            for(int i=0;i<graph[now].size();i++){
                int cost = t+graph[now][i].second;
                
                if(cost<time[graph[now][i].first]){
                 
                    time[graph[now][i].first]=cost;
                    q.push({cost,graph[now][i].first});
                }
           
            }

        }

    }
    int mx=0;
    int count=0;
    for(int i=1 ;i<=N;i++){
        if(time[i]<INF)
        {
            count++;
            if(mx<time[i]){
                mx=time[i];
            }
        }
    }
    cout<<count-1<<' '<<mx<<'\n';
    
    
}