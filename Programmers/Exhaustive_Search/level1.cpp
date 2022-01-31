#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores;
    int score=0;    
    vector<vector<int>> gum;
    vector<int> st1({1,2,3,4,5});
    vector<int> st2({2,1,2,3,2,4,2,5});
    vector<int> st3({3,3,1,1,2,2,4,4,5,5});
    gum.push_back(st1);
    gum.push_back(st2);
    gum.push_back(st3);

    for(int i=0;i<gum.size();i++){
        score=0;
        for(int k=0;k<answers.size();k++){
            if(gum[i][ k%gum[i].size() ]==answers[k]){
                score++;
            }
        }
        if(scores.empty()||scores.front()<=score){
            if(scores.empty()){
                scores.push_back(score);
                answer.push_back(i+1);
            }
            else if(scores.back()==score){
                answer.push_back(i+1);
                scores.push_back(score);
            }
            else{
                answer.clear();
                scores.clear();
                answer.push_back(i+1);
                scores.push_back(score);
            }
        }
    }


    return answer;
}

int main(){
    vector<int> answer= solution({1,2,3,4,5,1,2,3,4,5});
    
    for(auto a : answer){
        cout<<a<<' ';
       }

}