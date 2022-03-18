#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int Parent[51];

int find_parent(int X){
    if(Parent[X]!=X){
        Parent[X]=find_parent(Parent[X]);
    }
    return Parent[X];
}

void union_parent(int a, int b){
    a=find_parent(a);
    b=find_parent(b);

    Parent[b]=a;
}

int main(){
    int N,M;
    cin>>N>>M;
    int n ;
    int answer = M;
    vector<vector<int>> v;
    vector<int> tru;
    cin>>n;
    for(int i =0 ; i <N+1;i++){
        Parent[i]=i;
    }
    int num;
    for(int i =0 ; i < n;i++){
        cin>>num;
        if(num==0){
            cout<<M<<'\n';
            return 0;
        }
        tru.push_back(num);
    }
    for(int i =0 ; i < M ;i++){
        cin>>n;
        vector<int> a;
        v.push_back(a);
        for(int k =0 ; k < n;k++){
            cin>>num;
            v[i].push_back(num);
        }
    }
    for (int i = 0; i < M; i++)
    {
        int N1 = v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            int N2 = v[i][j];
            union_parent(N1, N2);
        }
    }
    bool check=true;
    for (int i = 0; i < M; i++)
    {
        check=true;
        for(int j = 0 ; j < v[i].size();j++){
            int N1= v[i][j];
            for(int k= 0 ; k < tru.size();k++){
                if(!check)
                break;
                int N2=tru[k];

                if(find_parent(N1)==find_parent(N2)){
                    
                    check=false;
                    break;
                }
            }
        }
        if(!check)answer--;
    }
    cout<<answer<<'\n';
    return 0;

}