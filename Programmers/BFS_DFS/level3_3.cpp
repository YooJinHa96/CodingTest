#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<vector<string>> ans;
map<string, vector<string>> mp;
map<pair<string, string>, int> visit;
bool DFS(string start, string end, vector<string> path, vector<vector<string>> &tickets)
{
    path.push_back(end);

    if (path.size() == tickets.size()+1)
    {
        ans.push_back(path);
        return true;
    }
    else
    {
        for (int i = 0; i < mp[end].size(); i++)
        {
            if (visit[make_pair(end, mp[end][i])] > 0)
            {
                visit[make_pair(end, mp[end][i])]--;
                bool check=DFS(end, mp[end][i], path, tickets);
                if(check) return true;
                visit[make_pair(end, mp[end][i])]++;
            }
        }
        return false;
    }
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    for (auto ticket : tickets)
    {
        visit[make_pair(ticket[0], ticket[1])]++;
        mp[ticket[0]].push_back(ticket[1]);
        sort(mp[ticket[0]].begin(), mp[ticket[0]].end());
    }
    vector<string> path;
    path.push_back("ICN");
    for (int i = 0; i < mp["ICN"].size(); i++)
        {
            visit[make_pair("ICN", mp["ICN"][i])]--;
            bool check = DFS("ICN", mp["ICN"][i], path, tickets);
            if(check) break;
            visit[make_pair("ICN", mp["ICN"][i])]++;
        }
    answer = ans[0];
    return answer;
}