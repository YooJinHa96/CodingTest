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