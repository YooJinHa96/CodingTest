/*

union-find  �ڷᱸ��

*/

#include <iostream>
#include <algorithm>

using namespace std;

int Parent[100];

int find_parent(int X){

    if( Parent[X]!=X){
        return find_parent(Parent[X]);
    }
    return X;

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
    cin>>V>>E;
    
    for(int i=0; i<=V;i++){
        Parent[i]=i;
    }

    for(int i=0;i<E;i++){
        cin>>a>>b;
        union_parent(a,b);
    }

    cout<<"�� ���Ұ� ���� ����: ";
    for(int i=1;i<=V;i++){
        cout<<find_parent(i)<<' ';
    }
    cout<<'\n';
    cout<<"�θ� ���̺�: ";
    for(int i=1;i<=V;i++){
        cout<<Parent[i]<<' ';
    }
}