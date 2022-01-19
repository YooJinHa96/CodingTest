/*

Programmers Heap 디스크 컨트롤러

[작업이 요청되는 시점, 작업의 소요시간]으로 모든 작업이 처리되는 걸리는 평균 시간들 중 최소 시간 구하기
작업이 실행하고 있는 도중에 다른 작업이 요청되는 시점이 있다면 대기 상태로 들어감.

-> 최소값으로 풀기위해 대기하고 있는 작업들중에서 가장 작업의 소요시간이 작은 것들을 먼저 실행 <- sort 진행 
우선순위큐를 이용해서 대기상태중에서 가장 작업시간이 작은 것들이 top으로 나오도록 진행

우선 작업 요청되는 시점을 기준으로 sort하여 queue 넣음
그리고 queue에서 큐(q1) 꺼내고 이걸 기준으로 queue에서 계속 값(q2)을 꺼냄.
q1에 작업의 소요시간과 q2의 작업이 요청되는 시점을 비교 <- 이는 q1이 작업하는 동안 q2들의 작업 요청 시간이 와도 작업을 하고 있어 대기중에 들어가야하는 값들을 의미
q2 값들 대기상태에 들어가야하는 q값들들 우선순위 큐에 넣음

q1의 작업 소요시간보다 q2작업이 요청되는 시점이 더 큰것이 나오면 우선순위 큐에서 값(q3)를 꺼냄 <- q1이 작업이 끝나고 대기상태중인 것들중에 작업시간이 가장 짧은 것 하나를 꺼내서 실행시키는 의미.

위에 순서들을 반복 하다가 queue가 빈 값이되면 반복 탈출 <- 다 대기상태이거나 처리됬다는걸 의미
우선순위 큐에 있는 값들을 꺼내어 시간 마저 계산 <- 대기 상태에들 처리 


----문제 푸는데 오래 걸린 에러----
처음시작점과 끝점을 입력하는 부분에서 끝점을 end = 작업의 소요시간으로 처리함 <- 이러면 시작점이 0일때는 상관없지만 그 외에서 망함. 
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


bool comvec(vector<int> a, vector<int> b)
{

    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
    {
        return a[0] < b[0];
    }
}
class cmp
{
public:
    bool operator()(pair<int, int> pq1, pair<int, int> pq2)
    {
        if (pq1.second == pq2.second)
        {
            return pq1.first < pq2.first;
        }
        else
        {
            return pq1.second > pq2.second;
        }
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    queue<pair<int, int>> q;

    sort(jobs.begin(), jobs.end(), comvec);
    
    for (int i = 0; i < jobs.size(); i++)
    {

        q.push({jobs[i][0], jobs[i][1]});
    }

    int start, end;

    start = q.front().first;
    end = start + q.front().second;
    sum += end - start;
    q.pop();
  
    while (!q.empty())
    {

        if (end >= q.front().first)
        {
            pq.push({q.front().first, q.front().second});
            q.pop();
        }
        else
        {
            if (!pq.empty())
            {

                int wait = end - pq.top().first;
                start = end;
                end = start + pq.top().second;
                sum = sum+ wait + pq.top().second;
                pq.pop();
            }
            else{
               if(!q.empty()){

                    start = q.front().first;
                    end = start+q.front().second;
                    sum += q.front().second;
                    q.pop();
                }
            }
        }
    }
    while (!pq.empty())
    {
        int wait = end - pq.top().first;
        start = end;
        end = start + pq.top().second;
        sum = sum+ wait +pq.top().second;
        pq.pop();
    }
    answer = sum / jobs.size();
    return answer;
}

int main()
{
   // int answer = solution({{0, 3}, {1, 9}, {2, 6}, {7, 10}, {3, 5}, {5, 3},{40,5},{43,7}});
   //int answer = solution({{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34},{15, 2}, {35, 43}, {26, 1}});
    int answer=solution({{1000,1000}});
    int sum = 15;

    cout << answer << '\n';
}