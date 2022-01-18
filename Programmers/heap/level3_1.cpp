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
    end = q.front().second;
    sum+= end-start;
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
            cout<<"ds "<<q.front().first<<" "<<q.front().second<<"\n";
           while(!pq.empty()){
                cout<<pq.top().first<<" "<<pq.top().second<<'\n';
                pq.pop();
            }
            /*
            while (!pq.empty())
            {
                int wait = end - pq.top().first;
                int time = wait + pq.top().second;
                sum += time;
                end = end + pq.top().second;
                pq.pop();
            }
            */
            start = q.front().first;
            end = q.front().second;
            sum+=end-start;
            q.pop();
        }
    }
    while(!pq.empty()){
                cout<<pq.top().first<<" "<<pq.top().second<<'\n';
                pq.pop();
            }
    /*
    while (!pq.empty())
    {
             
        int wait = end - pq.top().first;
        int time = wait + pq.top().second;
        sum += time;
        end = end + pq.top().second;
        pq.pop();
    }
    */
    cout<<sum<<'\n';
    answer = sum / jobs.size();
    return answer;
}

int main()
{
    int answer = solution({{0, 3}, {1, 9}, {2, 6},{7,10},{3,5},{5,3}});
    int sum=15;
    
    cout << answer << '\n';
}