#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    size_t size= tickets.size();
    queue<pair<string,string>> q;
    map<pair<string,string>,bool> visit;
    map<string,vector<string>> mp;
    for(auto ticket : tickets){
        visit[make_pair(ticket[0],ticket[1])]=false;
        mp[ticket[0]].push_back(ticket[1]);
        sort(mp[ticket[0]].begin(),mp[ticket[0]].end());
    }
    string start,end;
    start= tickets[0][0];
    end=mp[ tickets[0][0] ][0];
    q.push(make_pair(start,end));
    answer.push_back(start);
    visit[make_pair(start,end)]=true;
    while(!q.empty()){
        size=q.size();
        for(int i =0 ; i < size;i++){
            start=q.front().first;
            end=q.front().second;
            answer.push_back(end);
            q.pop();

            for(int k =0 ;k < mp[end].size();k++){
                    if(!visit[make_pair(end,mp[end][k])] ){
                        q.push(make_pair(end,mp[end][k]));
                        visit[make_pair(end,mp[end][k])] = true;
                        break;
                    }
            }


        }
        if(q.empty()){
            if(answer.size()==mp.size()){
                break;
            }
            else{
                
            }
        }
    }


    return answer;
}