#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int maxA=0;
    sort(citations.begin(),citations.end());
    for(int h=1 ;h<=citations.size();h++){
       int check=0;
        for(int k=0;k<citations.size();k++){
            if(citations[k]>=h){
                check++;
            }
        }
        if(check>=h){
            answer=h;
        }

    }
    
    return answer;
}

int main(){
    int answer=solution({1,1,5,7,6}); // 0 0,0,3  5 6
    cout<<answer<<'\n';
}