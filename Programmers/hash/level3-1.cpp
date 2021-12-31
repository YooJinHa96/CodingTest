/*
 Programmers hash 베스트앨범

 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두개씩 뽑아서 출력
 
 기준 
 1. 속한 노래가 많이 재생된 장르를 먼저 수록
 2. 장르 내에서 많이 재생된 노래를 먼저 수록
 3. 장르 내에서 재생 획수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록

 key 를 장르로 정해서 두개의 map을 사용 -> <장르, 플레이수> <장르,<고유번호, 플레이수>> 
 map mp -> (장르, 플레이수)<- 기준 1번 장르별로 플레이 수 합을 파악하기 위해 <-같은 장르들의 플레이 수들을 다합치도록 진행
 map mp2 -> (장르, (고유번호, 플레이수)) -> 기준 2, 3을 위해 기준 1을 끝내고 그 후 장르에 속한 음악들의 플레이 수들 끼리 비교(정렬)과 고유 번호파악하기 위해

 ###
 c++에서 map <key,value> value값에 의한 정렬은 vector에 따로 넣어서 진행해야함
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
bool compare2(pair<int, int> a, pair<int, int> b)
{
    if( a.second==b.second){

        return a.first<b.first;

    }
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> mp;                     //<음악종류, 플레이수>; -> 1번 조건 총플레이수를 통한 정렬을 위해
    map<string, vector<pair<int,int>>> mp2; //<음악종류, <고유번호,플레이수>> -> 2번 조건 정렬을 위해

    for (int i = 0; i < genres.size(); i++)
    {
        mp[genres[i]] += plays[i];
        mp2[genres[i]].push_back(make_pair(i, plays[i]));
    }

    //map을 키값에 의한 정렬을 위해 vector로 옮겨서 작업해야함
    vector<pair<string, int>> vec(mp.begin(), mp.end()); 
    sort(vec.begin(), vec.end(), compare);//pair<int, string>으로 하면 default로 앞에 값으로 정렬 가능
    
    for (auto m : vec)
    {   
        /* 
        vector<pair<int, int>> vec2(mp2[m.first].begin(), mp2[m.first].end());
        sort(vec2.begin(), vec2.end(), compare2);
    
        answer.push_back(vec2[0].first);
        if(vec2.size()!=1)//한 곡일 때 예외 처리
        answer.push_back(vec2[1].first);
        */
       
        sort(mp2[m.first].begin(), mp2[m.first].end(), compare2);
        answer.push_back(mp2[m.first][0].first);
        if(mp2[m.first].size()!=1)//한 곡일 때 예외 처리
        answer.push_back(mp2[m.first][1].first);
    }
    
    return answer;
}

int main()
{
    vector<int> answer=solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
    
}