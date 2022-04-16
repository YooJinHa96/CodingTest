#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    queue<int> q;
    vector<int> v;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int answer=0;
    int count =0;
    int index=0;
    sort(v.begin(), v.end());
    for(auto a : v){
        q.push(a);
    }
    for (int i = 1; i <= N; i++)
    {
        count =0;
        for (int k = 0; k < i; k++)
        {
            if(!q.empty()){
                q.pop();
                count++;
            }
        }
        if(count == i){
            answer++;
        }
        if(q.empty()){
            break;
        }
        
    }
    cout<<answer<<'\n';
}