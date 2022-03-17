#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans=0;
void bs(int left, int right, vector<int> & card,int target){

    if(left<=right){
        int mid=(left+right)/2;

        if(card[mid]==target){
            ans++;
            bs(mid +1, right,card,target);
            bs(left,mid-1,card,target);
        }
        else{
            if(card[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
            bs(left,right,card,target);
        }
    }
}
int main()
{
    int N, M;
    vector<int> card;
    vector<int> s_card;
    vector<int> answer;
    int num;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        card.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        s_card.push_back(num);
    }
    sort(card.begin(),card.end());

    int left =0;
    int right = card.size()-1;

    for(auto c : s_card){
        ans=0;
        bs(left,right,card,c);
        answer.push_back(ans);
    }

    for(auto a : answer){
        cout<<a<<' ';
    }
    cout<<'\n';
}