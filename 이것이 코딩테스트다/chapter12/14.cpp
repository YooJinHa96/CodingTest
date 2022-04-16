#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int ans = 100000000;
map<int, bool> visit;
vector<int> a;
//  dir 1 시계 -1 반시계
void Search(int count, int fr, vector<int> &weaks, vector<int> &dist, int w_index, int d_index)
{

    if (count >= weaks.size() / 2)
    {
        a.push_back(fr - 1);
        return;
    }
    else if(fr == dist.size()+1){
       
        return ;
    }
    else
    {
        int n = 0;
        int c = -1;
        int b = weaks[w_index] + dist[d_index];

        for (int i = w_index; i < weaks.size(); i++)
        {
            if (b < weaks[i])
            {
                c = i;
                break;
            }
            else
            {
                n++;
            }
        }
        bool check = false;
        for (int i = 0; i < dist.size(); i++)
        {

            if (!visit[i])
            {            
                check=true;
                visit[i] = true;
                Search(count + n, fr + 1, weaks, dist, c, i );
                visit[i] = false;
            }
        }
        if(!check) Search(count+n, fr+1, weaks,dist,c,d_index );
    }
}
int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    vector<int> weaks;
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < weak.size(); k++)
        {
            weaks.push_back(weak[k] + n * i);
        }
    }

    sort(dist.begin(), dist.end(), greater<int>());
    for (int j = 0; j < dist.size(); j++)
    {
        visit[j] = true;
        for (int i = 0; i < weaks.size(); i++)
        {
            
            Search(0, 1, weaks, dist, i, j);
        }
        visit[j] = false;
    }

    if (a.size() == 0)
    {
        answer = -1;
    }
    else
    {
        answer = *min_element(a.begin(), a.end());
    }
    return answer;
}
int main()
{

    // int answer = solution(12, {1, 5, 6, 10}, {1, 2, 3, 4});
    //int answer = solution(200, {0, 10, 50, 80, 120, 160}, {1, 10, 5, 40, 30});
 int answer = solution(30, {0, 3, 11, 21}, {10, 4});
    cout << answer << '\n';
}