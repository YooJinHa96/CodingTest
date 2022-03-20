#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<int> Parent;

void DFS(int Node,vector<int> & ans){


    if(tree[Node].size()==0){
        return ;
    }
    else{
        for(int i =0 ; i <tree[Node].size();i++){
    
            ans.push_back(tree[Node][i]);
            DFS(tree[Node][i],ans);
        }
    }

}
int main(){

    int T;
    int N;
    cin>>T;
    int a,b;
    for(int i =0 ; i< T ; i++){
        cin>>N;
        tree.clear();
        tree.resize(N);
        for(int k = 0 ; k<N;k++){
            vector<int> p;
            tree.push_back(p);
        }
        for(int k =0 ;k < N-1;k++){
            cin>>a>>b;
            tree[b-1].push_back(a-1);

        }
        vector<int> ans1,ans2;
        cin>> a>>b;
        ans1.push_back(a-1);
        ans2.push_back(b-1);
        DFS(a-1,ans1);
        DFS(b-1,ans2);
        int answer=-1;

        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());

        for(int k=0; k<ans1.size();k++){
            int an=ans1[k];
            for(int j=0;j<ans2.size();j++){
                        if(an==ans2[j])
                        {
                            answer=ans2[j];
                            break;
                        }
            }
        }
        cout<<answer+1<<'\n';
       
    }
    return 0;
}