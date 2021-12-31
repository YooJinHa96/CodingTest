/*
 Programmers hash 위장 
 위장할 옷의 종류에 따른 나올 수 있는 경우의 수 찾기
 
 다른 옷을 입었을 경우 꼭 다른 종류의 옷은 안입어도 되므로 경우의 수를 안입는 것를 포함하기 위해 +1 해서 계산
 마지막에 다 안 입는 경우는 제외해야하므로 -1

 옷이 어떤 종류이고 종류당 몇개 있는지를 체크하기 위해 map을 사용 
  map의 key -> 옷의 종류 value -> 몇개
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    map<string, int> mp;
    for(int i=0;i<clothes.size();i++){
            mp[clothes[i][1]]++; //<-  mp.insert(make_pair(clothes[i][1],1));
    }
    //경우의 수로 안 입는 것까지 포함하기 위해 +1 . 예시 2가지면 총 3가지
    for(auto m : mp){
        answer*=(m.second + 1 );
    }
    /* 아무것도 안입는 경우 제외*/
    answer-=1;
    return answer;
}

int main(){
    int answer = solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});
    cout<<answer<<'\n';
    }