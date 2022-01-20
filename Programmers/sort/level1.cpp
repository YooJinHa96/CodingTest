#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> s_array;
    for(auto c : commands){
        s_array.resize(c[1]-c[0]+1);
        
        copy(array.begin()+c[0]-1,array.begin()+c[1],s_array.begin());
     
        sort(s_array.begin(),s_array.end());
        
        answer.push_back(s_array[c[2]-1]);
        
        s_array.clear();
    }
    return answer;
}

int main(){
    vector<int> answer;
    answer=solution({1, 5, 2, 6, 3, 7, 4},{{2,5,3},{4,4,1},{1,7,3}});
    for( auto a : answer){
        cout<<a<< " ";
    }
}