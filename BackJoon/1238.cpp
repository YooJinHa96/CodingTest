#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define INF (int)1e9

using namespace std;

int main(){
      ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N,M,X;

    vector<int> distance;
     vector<int> r_distance;
    vector<vector<pair<int,int>>> graph;
    vector<vector<pair<int, int>>> r_graph;
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
    visit[X]=true;
    r_distance[X]=0;
    r_visit[X]=true;
    for(int i=0;i<graph[X].size();i++){

        distance[graph[X][i].first]=graph[X][i].second;
  
    
    }
     for(int i=0;i<r_graph[X].size();i++){

        r_distance[r_graph[X][i].first]=r_graph[X][i].second;
    
    }
    int min_val=INF;
    int r_min_val=INF;
    for(int i=1;i<N+1;i++){       
        min_val=INF;
        r_min_val=INF;
        for(int j=N ;j>0;j--){  
         
            if(distance[j]<min_val&&!visit[j]){
         
                min_val=distance[j];
                X=j;
                visit[X]=true;
            }
            if(r_distance[j]<r_min_val&&!r_visit[j]){
         
                r_min_val=r_distance[j];
                R_X=j;
               r_visit[R_X]=true;
         
            }
        }
        for(int k=0;k<graph[X].size();k++){
            distance[ graph[ X ][ k ].first ] = min(distance[ graph[ X ][ k ].first ],distance[ X ]+graph[ X ] [ k ].second);
        }
        for(int k=0;k<r_graph[R_X].size();k++){
            r_distance[ r_graph[ R_X ][ k ].first ] = min(r_distance[ r_graph[R_X ][ k ].first ],r_distance[ R_X ]+r_graph[ R_X ] [ k ].second);
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
