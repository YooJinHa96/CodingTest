#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int x,int y){
    return x>y;
}
int main(){
    
    int N;
    int array[500];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    sort(array,array+N,compare);
    
    for(int i=0;i<N;i++){
        cout<<array[i]<<' ';

    }
    

}