/*

Programmers 완전탐색 모의고사 (수포자들)

학생들이 찍은 규칙적인 답들과 정답들을 비교하여 많이 맞춘 사람 출력

Vector answer -> 학생(인덱스)번호??  넣기 위해  
Vector score -> answer에 학생을 넣을때 그학생의 점수를 보관하기 위해 -> 그 다음 학생의 점수과 비교하기 위해 사용

첫번째 학생부터 반복 진행.

문제 수 만큼 반복 하며 학생이 찍은 답들과 비교

맞춘 정답 수와 이전 학생의 정답 수를 비교  -> 이전보다 많이 맞춰으면 vector를 비우고 현재 학생의 인덱스 값과 정답수를 vector에 넣음
만약에 같으면 그 다음 값으로 넣음. 단 학생 인덱스 값만 넣고, 점수는 안넣어도 무방.

학생들의 찍은 답들은 일정한 규칙이 존재 하므로 -> %를 이용해 원형 큐처럼 접근 
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores;
    int score=0;    
  
    vector<vector<int>> gum({{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}});
  
    for(int i=0;i<gum.size();i++){
        score=0; //점수
        for(int k=0;k<answers.size();k++){
            if(gum[i][ k%gum[i].size() ]==answers[k]){ 
                score++; //맞출 때마다 점수 ++
            }
        }
        if(scores.empty()||scores.front()<=score){
            if(scores.empty()){ //비어있을때 
                scores.push_back(score);
                answer.push_back(i+1);
            }
            else if(scores.back()==score){
                answer.push_back(i+1);
            }
            else{//이전 학생보다 클때
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