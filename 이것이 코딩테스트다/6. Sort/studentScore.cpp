#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

bool compare(pair<string, int> x,pair<string, int> y){
    return x.second<y.second;
}
int main(){
    
    int N,score;
    string name;
    vector<pair<string,int>> stu;


    
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>name>>score;
        stu.push_back(make_pair(name,score));
    }
    sort(stu.begin(),stu.end(),compare);
    for(int i=0; i<N;i++){
        cout<<stu[i].first<<' ';
    }
    

}