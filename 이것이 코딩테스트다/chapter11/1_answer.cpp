#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    int answer=0;
    int count =0;

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        count ++;
        if(count>=v[i]){
            answer++;
            count=0;
        }
        
    }
    cout<<answer<<'\n';
}