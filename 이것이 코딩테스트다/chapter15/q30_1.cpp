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
        first_index = query.find('?') == 0 ? query.rfind('?') + 1 : 0;
        int last_index = first_index == 0 ? query.find('?') - 1 : query_len - 1;

        sub_size = last_index - first_index + 1;
        string qur_sub = query.substr(first_index, sub_size);
        left = 0;
        right = r_mp[query.length()].size() - 1;

        if( qur_sub == "?" ){
            for(auto s : mp[query_len]){
                if(s.length()==query_len){
                    cnt++;
                }
            }
        }
        else if(first_index!=0){
            string q_r = query.substr(first_index, sub_size);
            first_index = 0;
            reverse(q_r.begin(), q_r.end());
            left = 0;
            right = r_mp[query.length()].size() - 1;
            bs(left, right, r_mp[query.length()], q_r);
        }
        else
            bs(left, right, mp[query.length()], query.substr(first_index, sub_size));
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