/*
 Progrmmers hash 전화번호 목록
 한 번호가 다른 번호의 접두어인지 확인 문제
 접두어가 있으면 false 없으면 true 반환
 
 문자열로 주기 때문에 정렬을 해도 아스키코드 값으로 정렬이 됨을 이용
 그 다음 i번째랑 i+1만 확인 <- 문자열순으로 정렬되어기 떄문에
 접두어이기 때문에 i번쨰의 길이만큼만 i+1을 잘라서 확인 -> substr 사용
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    
    string number;
    bool answer = true;
  
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {

        number = phone_book[i];
        string str = phone_book[i + 1].substr(0, number.length());
        
        if (str == number)
        {
            answer = false;
            return answer;
        }
    }
    return answer;
}