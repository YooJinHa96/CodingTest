#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N,x;
int answer=0;
void bs(int left, int right, vector<int> &v){

    int mid = (left+right)/2;

    if(left<=right){
        if(mid==v[mid]){
            answer=mid;
            return;
        }
        else{
            if(mid>v[mid]){
                bs(mid+1,right,v);
            }
            else{
                bs(left,mid-1,v);
            }
        }
    }

}
int main(){
    int num;
    vector<int> v;
    cin>>N;
    for(int i =0 ;i<N;i++){
        cin>>num;
        v.push_back(num);
    }

    int left=0;
    int right=v.size()-1;
    int mid =(left+right)/2;
    bs(left,right,v);

    if(answer==0){
        answer=-1;
    }
    cout<<answer<<'\n';   

}