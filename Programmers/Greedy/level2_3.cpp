
/*
    Programmers Greedy 구멍보트

    최대 2명 탈 수 있는 구멍 보트. 구멍보트를 최소한으로 사용하는 개수 구하기

    1. 사람의 무게를 기준으로 오름차순으로 정렬

    2. 제일 앞 사람과 제일 뒷사람의 무게를 합쳐서 보트의 무게보다 작으면 보트 하나 추가 
       - > 보트 무게 안에서 제일 최대한 무겁게 들고가야함. 

    3. 그 후 제일 뒷사람 pop을 이용해서 제거, 앞 사람은 index 값으 다음 값으로 넘어가면서 제거

    4. 두 사람의 무게가 보트보다 무거우면 뒷사람만 제거 
      - 그 다음으로 무거운 사람과 같이 태울수도 있기 때문에



*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int weight = limit;
    sort(people.begin(), people.end());
    
    int i=0;
    while(i<people.size()){
        if(limit>=people[i]+people.back()){
            answer++;
            i++;
        }
        else
        answer++;

        people.pop_back();

    }
    return answer;
}