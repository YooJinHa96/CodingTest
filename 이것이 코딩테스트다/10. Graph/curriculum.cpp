#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main(){
    int N;
    queue<int> q; 
    cin>>N;
    vector<int> indegrees;
    indegrees.resize(N);
    vector<int> timer;
    vector<vector<int>> subject;
    vector<int> answer;
    vector<int> sub_ans;
    int time,sub;
    subject.resize(N);
    answer.resize(N);
    sub_ans.resize(N);
    for(int i =0 ; i<N;i++){
        cin>>time;
        timer.push_back(time);
        vector<int> v;
        while(1){
            cin>>sub;
            if(sub==-1){
                break;
            }
            subject[sub-1].push_back(i);
            indegrees[i]++;
        }
    }
    for(int i =0 ;i<N;i++){
        answer[i]=timer[i];
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int a=q.front();
        q.pop();
        

        for(int i =0 ; i < subject[a].size();i++){
                indegrees[subject[a][i]]--;
                answer[subject[a][i]]=max(answer[subject[a][i]],answer[a]+ timer[subject[a][i]]);
                if(indegrees[subject[a][i]]==0){
                    q.push(subject[a][i]);
                }
        }


    }
    for(auto ans : answer){
        cout<<ans<<'\n';
    }
}