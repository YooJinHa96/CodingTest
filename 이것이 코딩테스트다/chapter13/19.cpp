#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int N;
vector<int> num;
vector<int> sign;
int max_answer = -1000000000, min_answer=1000000000;

void DFS(int index, int tempresult){
    if(index==N){
        max_answer=max(max_answer,tempresult);
        min_answer=min(min_answer,tempresult);
    }
    else{
        if(sign[0]>0){
            sign[0]--;
            DFS(index+1,tempresult+num[index]);
            sign[0]++;
        }
        if(sign[1]>0){
            sign[1]--;
            DFS(index+1,tempresult-num[index]);
            sign[1]++;
        }
        if(sign[2]>0){
            sign[2]--;
            DFS(index+1,tempresult*num[index]);
            sign[2]++;
        }
        if(sign[3]>0){
            sign[3]--;
            DFS(index+1,tempresult/num[index]);
            sign[3]++;
        }
    }
}
int main(){
    
    cin>>N;
    int a;
  
    for(int i =0 ; i < N;i++){
        cin>>a;
        num.push_back(a);
    }
    for(int i =0 ; i < 4;i++){
        cin>>a;
        sign.push_back(a);
    }
    DFS(1,num[0]);   
    cout<<max_answer<<'\n';
    cout<<min_answer<<'\n';
}