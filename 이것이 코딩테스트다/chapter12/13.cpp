#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int N, M;
int arr[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> clzls;
map<pair<int, int>, bool> visit;
int answer = 1000000000;
void distance_clzls(vector<pair<int, int>> &selected)
{
   
    vector<int> house_clzls;
    for (int i = 0; i < house.size(); i++)
    {
        int sum = 1000000000;
        for (int j = 0; j < selected.size(); j++)
        {
            int r1_r2 = abs(house[i].first - selected[j].first);
            int c1_c2 = abs(house[i].second - selected[j].second);
            sum = min(sum, r1_r2 + c1_c2);
        }
        house_clzls.push_back(sum);
    }
    answer = min(answer, accumulate(house_clzls.begin(), house_clzls.end(), 0));
}
void choose_clzls(int idx, vector<pair<int, int>> &selected)
{
    if (selected.size() == M)
    {
        distance_clzls(selected);
        return;
    }
    else
    {
        for (int i = idx; i < clzls.size(); i++)
        {
            int x = clzls[i].first;
            int y = clzls[i].second;
            if (!visit[{x, y}])
            {
                visit[{x, y}] = true;
                selected.push_back({x, y});
                choose_clzls(i,selected);
                visit[{x, y}] = false;
                selected.pop_back();
            }
        }
        return;
    }
}
int main()
{

    cin >> N >> M;
    int a;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                house.push_back({i, j});
            }
            else if (arr[i][j] == 2)
            {
                clzls.push_back({i, j});
            }
        }
    }
    vector<pair<int, int>> selected;
    for (int i = 0; i < clzls.size(); i++)
    {
        int x = clzls[i].first;
        int y = clzls[i].second;
        visit[{x, y}] = true;
        selected.push_back({x, y});
        choose_clzls(i,selected);
        visit[{x, y}] = false;
        selected.pop_back();
    }

    cout<<answer<<'\n';
    return 0;
}