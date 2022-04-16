#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int query_len;
int first_index;
int sub_size;
int cnt = 0;
string wildTo(string s, char to) {
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '?') s[i] = to;
    }
    return s;
}
void bs(int left, int right, vector<string> &words, string query_sub)
{

    int mid = (left + right) / 2;

    if (left <= right)
    {

        mid = (left + right) / 2;

        string word_sub = words[mid].substr(first_index, sub_size);

        if (word_sub == query_sub)
        {
            cnt++;

            bs(mid + 1, right, words, query_sub);
            bs(left, mid - 1, words, query_sub);
        }
        else
        {
            if (word_sub < query_sub)
                left = mid + 1;
            else
                right = mid - 1;
            bs(left, right, words, query_sub);
        }
    }
}
vector<int> solution(vector<string> words, vector<string> queries)
{

    vector<int> answer;
    vector<string> re_words;
    map<int, vector<string>> mp;
    map<int, vector<string>> r_mp;
    for (auto s : words)
    {
        reverse(s.begin(), s.end());
        re_words.push_back(s);
    }
    sort(words.begin(), words.end());
    sort(re_words.begin(), re_words.end());
    for (int i = 0; i < words.size(); i++)
    {
        mp[words[i].length()].push_back(words[i]);
        r_mp[re_words[i].length()].push_back(re_words[i]);
    }

    int left = 0;
    int right = words.size() - 1;
    int mid;
    //?가아닌 문자의 index를 갖자
    for (auto query : queries)
    {
        cnt = 0;
        query_len = query.length();
       
   
      if(query[0]=='?'){
            reverse(query.begin(), query.end());
            auto u = upper_bound(r_mp[query_len].begin(), r_mp[query_len].end(),wildTo(query,'z'));
            auto l = lower_bound(r_mp[query_len].begin(), r_mp[query_len].end(),wildTo(query,'a'));
       
            cnt=u-l;
        }
        else{
             auto u = upper_bound(mp[query_len].begin(), mp[query_len].end(),wildTo(query,'z'));
            auto l = lower_bound(mp[query_len].begin(), mp[query_len].end(),wildTo(query,'a'));
            cnt=u-l;
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?","?????"};
    vector<int> answer;
    answer = solution(words, queries);
    string str;

    sort(words.begin(), words.end());
    for (auto s : answer)
    {
        cout << s << ' ';
    }
}