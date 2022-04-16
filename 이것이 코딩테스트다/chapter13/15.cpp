#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N,M,K,X;
    queue<pair<int,int>> q;
    vector<bool> visit;
    vector<vector<int>> graph;
    vector<int> answer;
    cin>>N>>M>>K>>X;   
    int a,b;
    graph.resize(N+1);
    visit.resize(N+1);
    for(int i=0;i<M;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        
    }
    int count =0;
    q.push({X,0});

    while(!q.empty()){
        int s=q.front().first;
        int c=q.front().second;
        q.pop();
        
        for(int i =0 ; i <graph[s].size();i++){
            if(K==c+1){
                if(!visit[graph[s][i]]){
                    visit[graph[s][i]]=true;
                    answer.push_back(graph[s][i]);
                    
                }
            }
            if(!visit[graph[s][i]]){
                visit[graph[s][i]]=true;
                q.push({graph[s][i],c+1});
             
                          
            }
        }
    }

    if(answer.size()==0){
        cout<<-1<<'\n';
    }   
    else{
        sort(answer.begin(),answer.end());
        for(auto ans : answer){
            cout<<ans<<' ';
        }
        cout<<'\n';
        }
}