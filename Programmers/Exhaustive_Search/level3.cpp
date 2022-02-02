#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y_width,y_vertical;//
    int x_width,x_vertical;

    for(int i=1 ; i<=yellow; i++){

        y_vertical=i;
        if(yellow % i ==0){
            y_width=yellow / i;
        }
        else
        continue;
        
        int total=y_width*2+y_vertical*2+4;
        int x_width=y_width+2;
        int x_vertical=y_vertical+2;
        int left_carpet= brown-total;

        while(left_carpet>0){
            total=x_width*2+x_vertical*2+4;
            x_width=x_width+2;
            x_vertical=x_vertical+2;
            left_carpet=left_carpet-total;
        }
        if(left_carpet==0){
            answer.push_back(x_width);
            answer.push_back(x_vertical);
            break;
        }

        

    }

    return answer;
}

int main(){
    
    vector<int> answer = solution(36,64);
    //vector<int> answer=solution(3,3);
    //vector<int> answer=solution(24,24);
    for(auto a : answer)
    cout<<a<<'\n';
    

}