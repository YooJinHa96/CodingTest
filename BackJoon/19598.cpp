#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int,int>> conference;
bool cmp(pair<int, int> a, pair<int ,int> b){
    if(a.first==b.first)
        return a.second< b.second;
    else
        return a.first<b.first;
}
int main(){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int N;
    cin>>N;
    int a,b;
    vector<pair<int,int>> answer;
    for(int i =0 ;i <N;i++){
        cin>>a>>b;
        conference.push_back({a,b});
        q.push({a,b});
    }
    while(!q.empty()){
        int start = q.top().first;
        int end = q.top().second;
        q.pop();
        int index=-1;
        for(int i =0 ; i< answer.size();i++){
            if(answer[i].second<=start){
                index=i;
                break;
            }
        }
        if(index!=-1){
            answer[index]=make_pair(start,end);
        }
        else{
        answer.push_back(make_pair(start,end));
        }
    }
    //sort(conference.begin(),conference.end(),cmp);
    cout<<answer.size()<<'\n';
     
    
}