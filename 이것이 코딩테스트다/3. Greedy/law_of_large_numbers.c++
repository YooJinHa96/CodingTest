#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare (int a, int b){
    return a>b;
}
int main ()
{
    int N, M ,K;
    int num;
    vector<int> data;
    cin>>N>>M>>K;

    for (int i= 0 ; i<N;i++){
        cin>>num;
        data.push_back(num);
    }
    sort(data.begin(),data.end(), compare);
    
    int answer =0 ;

    for (int i = 0 ; i< M ;i++){
        for(int j=0;j<K;j++){
            answer+=data[0];
            M-=1;
        }
        answer+=data[1];
        M-=1;

    }
    cout<< answer << "\n";
}