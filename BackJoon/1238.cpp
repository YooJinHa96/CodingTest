#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define INF (int)1e9

using namespace std;

int main(){
    
    int N,M,X;

    vector<int> distance;
     vector<int> r_distance;
    vector<vector<pair<int,int>>> graph;
    vector<vector<pair<int, int>>> r_graph;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> r_q;
    vector<bool> visit;
    vector<bool> r_visit;
    int R_X;

    cin>>N>>M>>X;
    int a,b,x;
    R_X=X;
    for(int i=0;i<N+1;i++){   // 0번째를 미리 넣어서, 1부터 시작할 거 인덱스 헷갈리지 않게 하기~~~~~~~~~~~~~`
        vector<pair<int,int>> p;
        graph.push_back(p);
        r_graph.push_back(p);
    }

    for(int i =0 ; i < M ; i++){
        cin>>a>>b;
        cin>>x;
         graph[a].push_back(make_pair(b,x));
         r_graph[b].push_back(make_pair(a,x));
    }
    
    visit.resize(N+1);
    r_visit.resize(N+1);
    distance.resize(N+1);
    r_distance.resize(N+1);
    fill(distance.begin(),distance.end(),INF);
    fill(r_distance.begin(),r_distance.end(),INF);
    distance[X]=0;
 
    r_distance[X]=0;

  
    int min_val=INF;
    int r_min_val=INF;

    q.push({0,X});
    r_q.push({0,X});

    int dis, now;
    while(!q.empty()){
        dis=q.top().first;
        now=q.top().second;
 
        q.pop();

        if(!visit[now]){
            
            visit[now]=true;

            for(int i = 0 ; i <graph[now].size();i++){
                int cost = graph[now][i].second+dis;
           
                if(cost<distance[graph[now][i].first]){
                    distance[graph[now][i].first] =cost;
                    q.push({cost,graph[now][i].first});
                }
            }
        }
    }
  
     while(!r_q.empty()){
        dis=r_q.top().first;
        now=r_q.top().second;
        r_q.pop();

        if(!r_visit[now]){
            
            r_visit[now]=true;

            for(int i = 0 ; i <r_graph[now].size();i++){
                int cost = r_graph[now][i].second+dis;

                if(cost<r_distance[r_graph[now][i].first]){
                    r_distance[r_graph[now][i].first] =cost;
                    r_q.push({cost,r_graph[now][i].first});
                }
            }
        }
    }

    vector<int> sum;
    for(int i =1 ; i<N+1;i++){
        sum.push_back(distance[i]+r_distance[i]);
    }
    int answer=*max_element(sum.begin(),sum.end());
    cout<<answer<<'\n';
    
    return 0;

}
