/*

union-find를 이용한 무방향 그래프 싸이클 찾기
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Parent[100];

int find_parent(int X){

    if( Parent[X]!=X){
        Parent[X]=find_parent(Parent[X]);
    }
    return Parent[X];

}

void union_parent(int a, int b){
    a=find_parent(a);
    b=find_parent(b);
    if(a<b){
        Parent[b]=a;
    }
    else{
        Parent[a]=b;
    }
}
int main(){

    int V, E;
    int a, b;
    bool cycle=false;
    cin>>V>>E;
    
    for(int i=0; i<=V;i++){
        Parent[i]=i;
    }

    for(int i=0;i<E;i++){
        cin>>a>>b;

        if(find_parent(a)==find_parent(b)){
            cycle=true;
            break;
        }
        else
        union_parent(a,b);
    }
    if (cycle){
        cout<<"cycle"<<'\n';
    }
    else {
        cout<<"no cycle"<<'\n';
    }

    
}