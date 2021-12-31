/*

 앞에 예제 우선수위 큐를 이용해서 풀기 -> N에서 logN
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define INF (int)1e9


int main(){

    int N,M;
    int start;
    bool* visit;
    vector<vector<pair<int,int>>> graph;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int, int>>> q; //형태 기억
    int *distance;
    cin>>N>>M;;
    cin>>start;
    
    for(int i=0;i<N+1;i++){   // 0번째를 미리 넣어서, 1부터 시작할 거 인덱스 헷갈리지 않게 하기~~~~~~~~~~~~~`
        vector<pair<int,int>> p;
        graph.push_back(p);
    }
    
  
    visit=new bool[N+1];

    fill(visit,visit+(N+1),false);

    distance=new int[N+1];
    fill(distance,distance+(N+1),INF);

   
    int a,b,c;

    for(int i=0;i<M;i++){
        cin>>a>>b>>c; 
        graph[a].push_back(make_pair(b,c));
    }

    distance[start]=0;
    int min_val=INF;

    q.push({0,start}); //(거리, 노드)
    int dis, now;
    while(!q.empty()){
        dis=q.top().first;
        now=q.top().second;
        q.pop();

        if(!visit[now])
        {
            visit[now]=true;

            for(int i=0 ;i<graph[now].size();i++){

                int cost=graph[now][i].second+dis;
                if(cost<distance[ graph[now][i].first ]){
                    
                    distance[ graph[now][i].first ] = cost;
                    q.push( {cost, graph[now][i].first});
                
                }
            }

        }
        
        
    }

    for(int i=1 ;i<N+1;i++){
        cout<<distance[i]<<'\n';
    }


}