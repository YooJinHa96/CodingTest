/*

Programmers 완전탐색 모의고사 (수포자들)

학생들이 찍은 규칙적인 답들과 정답들을 비교하여 많이 맞춘 사람 출력

Vector answer -> 학생(인덱스)번호??  넣기 위해  
Vector Student(3) -> 1~3번학생의 맞춘 정답 수를 기록할 벡터

answers 문제수 만큼 반복 진행 하며 비교

조건문 if를 3개를 사용하여 1번,2번,3번을 한번이 비교 하며 맞추면 +1

Student에 가장 큰 값과 각 Student들의 값과 비교하여 같은 학생 번호를 answer에 넣음

학생들의 찍은 답들은 일정한 규칙이 존재 하므로 -> %를 이용해 원형 큐처럼 접근 
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> Student(3);
   
    vector<vector<int>> gum({{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}});
    
    for(int i=0;i<answers.size();i++){
        
        if(answers[i]==gum[0][ i%gum[0].size() ] ) 
            Student[0]++;
        if(answers[i]==gum[1][ i%gum[1].size() ])
            Student[1]++;
        if(answers[i]==gum[2][ i%gum[2].size() ])
            Student[2]++;
    }
    //sort(Student.begin(),Student.end());  //-> Student index는 그대로지만 맞춘 수가 바뀌므로 뒤에서 비교할때 망함
    //int Max=Student.back();
    int Max=*max_element(Student.begin(),Student.end());
    cout<<Max<<'\n';
    for(int i=0;i<3;i++){
        if(Max==Student[i])
            answer.push_back(i+1);
    }

    return answer;
}
int main(){
    vector<int> answer= solution({1,2,3,4,5});
    
    for(auto a : answer){
        cout<<a<<' ';
       }

}