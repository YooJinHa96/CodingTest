#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    queue<pair<int,int>> q;
    vector<vector<int>> graph;
    vector<pair<int,int>> answer;
    int N,M;
    int a,b;
    cin>>N>>M;
    vector<int> indegree(N);
    graph.resize(N);
    for(int i =0 ; i <N;i++){
        vector<int> g;
        graph.push_back(g);
    }
    for(int i =0 ;i <M;i++){
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        indegree[b-1]++;

    }
    for(int i =0 ;i <N;i++){
        if(indegree[i]==0){

            q.push({i,1});
        }
    }
    while(!q.empty()){

        int node=q.front().first;
        int term=q.front().second;
        q.pop();
        answer.push_back({node,term});

        for(int i = 0; i< graph[node].size();i++){
                indegree[graph[node][i]]-=1;
            if(indegree[graph[node][i]]==0){
                q.push({graph[node][i],term+1});
            }
            
        }

    }
    sort(answer.begin(),answer.end());
    for(auto a : answer){
        cout<< a.second<<' ';
    }
    
}