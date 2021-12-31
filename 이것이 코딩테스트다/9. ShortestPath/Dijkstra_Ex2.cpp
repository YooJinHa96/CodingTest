/*
    Dijkstra_Ex1 - > 2차원 배열로 구현되서 입력 받지 않는공간들을 0으로 처리 -> 노드 하나당 N개를 다봐야함
    -> 시간 공간 낭비라 생각 

    책 처럼 한 노드의 연결 된 수만큼 만들고 확인 하는 식으로 바꿔보고 싶어서 만듬.
    
    pair를 활용 해보자 마인드~~~
    2차원 벡터를 pair 자료형으로 만듬
    vector[0][0]=(1,2)
    vector[0][1]=(2,3)
    vector[1][0]=(4,5)
    앞 index는 노드 뒷 index -> 현재 노드의 연결된 노드 수 , pair 값 first -> 현재 노드랑 연결되 있는 노드 번호 
    second 현재 노드랑 first에 노드를 있는 간선(거리?) 값

    개인적으로 생각하는 단점 : distance에 index 활용 할 때 가독성이 떨어지는 느낌

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define INF (int)1e9

int main(){

    int N,M;
    int start;
    bool* visit;
    vector<vector<pair<int,int>>> graph;
    int *distance;
    cin>>N>>M;

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
    visit[start]=true;
    int min_val=INF;

    for(int i=0;i<graph[start].size();i++){

        distance[graph[start][i].first]=graph[start][i].second;
    
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
        for(int k=0;k<graph[start].size();k++){
            distance[graph[start][k].first]=min(distance[graph[start][k].first],distance[start]+graph[start][k].second);
        }
    }
    for(int i=1 ;i<N+1;i++){
        cout<<distance[i]<<'\n';
    }


}