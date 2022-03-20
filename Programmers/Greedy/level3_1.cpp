#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Parent[100];
int find_Parent(int X){

    if(Parent[X]!=X){
        Parent[X]=find_Parent(Parent[X]);
    }
    return Parent[X];
}
void union_Parent(int a, int b){

    a= find_Parent(a);
    b = find_Parent(b);

    if(a<b)
        Parent[b]=a;
    else{
        Parent[a]=b;
    }
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,pair<int,int>>> graph;
    for(int i =0 ; i <n;i++){
        Parent[i]=i;
    }
    for(auto cost : costs){
        graph.push_back({cost[2],{cost[0],cost[1]}});
    }
    sort(graph.begin(),graph.end());

    for(int i =0 ; i < graph.size();i++){
        int node1=graph[i].second.first;
        int node2=graph[i].second.second;
        int cost=graph[i].first;
        
        if(find_Parent(node1)!=find_Parent(node2)){
            union_Parent(node1,node2);
            answer+=cost;
        }
    }
    return answer;
}