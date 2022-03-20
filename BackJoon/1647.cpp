#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Parent_City;
int find_Parent(int X)
{
    if (Parent_City[X] != X)
    {
        Parent_City[X] = find_Parent(Parent_City[X]);
    }
    return Parent_City[X];
}

int main()
{

    int N, M;
    int a, b, c;
    int answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        Parent_City.push_back(i);
    }
    vector<pair<int, pair<int, int>>> cities;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        cities.push_back({c, {a - 1, b - 1}});
    }
    sort(cities.begin(), cities.end());
    vector<int> cost;
    for (auto city : cities)
    {

        if (find_Parent(city.second.first) != find_Parent(city.second.second))
        {

            Parent_City[find_Parent(city.second.first)] = find_Parent(city.second.second);
            cost.push_back(city.first);
            answer += city.first;
        }
    }
    answer -= *max_element(cost.begin(), cost.end());
    cout << answer << '\n';
    return 0;
}