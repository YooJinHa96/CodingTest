/*
  Programmers hash 완주하지 못한 선수
  참여 선수들과 완주한 선수들의 명단을 받고 완주하지 못한 선수 찾기
 
  정렬 한 다음 앞순서대로 명단의 이름이 같은지 확인
  다른 경우 -> 겹치지 않는 사람 즉 완주자에서 빠졌다는 뜻
  index를 저장
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   
    string answer;
    int index= participant.size()-1;
    sort(participant.begin(), participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i=0;i < completion.size();i++){ 
        if(participant[i]!=completion[i]){
            index=i;
            break;
        }
    }
    
    answer=participant[index];
   return answer;
}
int main(){

   string str=solution({"marina", "josipa", "nikola", "vinko", "filipa"},{"josipa", "filipa", "marina", "nikola"});
   cout<<str<<"\n";
}