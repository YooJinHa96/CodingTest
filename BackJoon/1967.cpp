#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<pair<int, int>> MAX_DISTANCE;

int N;
bool cmp (pair<int ,int> a, pair<int, int> b){
    if(a.first==b.first)
        return a.second<b.second;
    else{
        return a.first>b.first;
    }
}
void DFS(int parent, int Node, int dis)
{
    int dia = 0;
    dia = dis;

    if (tree[Node].size() == 1 && parent==tree[Node][0].first)
    {
        MAX_DISTANCE.push_back({dis, Node});
    }
    else
    {
     
        for (int i = 0; i < tree[Node].size(); i++)
        {
            
            if(parent!=tree[Node][i].first)
            DFS(Node,tree[Node][i].first, dia + tree[Node][i].second);
        }
    }
}
int main()
{

    cin >> N;
    if(N==1){
        cout<<0<<"\n";
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        vector<pair<int, int>> t;
        tree.push_back(t);
    }
    int a, b, c;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> c;
        tree[a - 1].push_back({b - 1, c});
        tree[b - 1].push_back({a - 1, c});
    }
    DFS(0, 0, 0);
    sort(MAX_DISTANCE.begin(),MAX_DISTANCE.end(),cmp);   
    int max_node=MAX_DISTANCE[0].second;
    MAX_DISTANCE.clear();
    DFS(max_node,max_node,0);
     sort(MAX_DISTANCE.begin(),MAX_DISTANCE.end(),cmp);   
    cout<< MAX_DISTANCE[0].first<<'\n';
    
    // int max_a=*max_element(answer.begin(),answer.end());
}