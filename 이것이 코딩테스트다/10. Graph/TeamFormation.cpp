#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Team;


int find_team(int T){
    if(Team[T]!=T){
        Team[T]=find_team(Team[T]);
    }
    return Team[T];
}

int main(){
    int N,M;
    vector<string> answer;
    cin>>N>>M;
    for(int i =0 ; i <N;i++){
        Team.push_back(i);
    }
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;

        if(a==0){
            Team[find_team(b)]=find_team(c);
        }
        else if(a==1){
            if(find_team(c)==find_team(b)){
                answer.push_back("YES");
            }
            else{
                answer.push_back("NO");
            }
        }
    }
    for(auto s : answer){
        cout<<s<<'\n';
    }

}