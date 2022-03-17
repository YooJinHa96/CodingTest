#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define INF (int)1e9

int main(){
    int n,m,r;
    vector<int> item;
    int graph[101][101];
    cin>>n>>m>>r;
    int c;
    for(int i =0 ;i < n;i++){
        cin>>c;
        item.push_back(c);
    }
    int a,b;
   
    for(int i=0 ;i<n;i++){
        fill(graph[i],graph[i]+(n),INF);
    }
    //자기 자신에서 자신으로 가는 비용 =0
    for(int i=0; i<n;i++){
        for(int k=0;k<n;k++){
            if(i==k){
                graph[i][k]=0;
            }
        }
    }
     for(int i = 0 ; i <r;i++){
        cin>>a>>b>>c;
        graph[a-1][b-1]=c;
        graph[b-1][a-1]=c;
    }
    for(int k=0 ; k <n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);   
            }
        }
    }


    vector<int> sum(n,0);
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if(graph[i][k]<=m)
                sum[i]+=item[k];
        }
    }
    int answer=*max_element(sum.begin(),sum.end());
    cout<<answer<<'\n';
    return 0;

}