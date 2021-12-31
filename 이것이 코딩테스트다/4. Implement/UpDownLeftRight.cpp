/*
공간의 크기 N
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    
    int N;
    int current_X=0;
    int current_Y=0;
    string move_plans; 
    cin >> N;
    cin.ignore();
    getline(cin, move_plans);

    move_plans.erase(remove(move_plans.begin(),move_plans.end(),' '),move_plans.end());
    
    for(int i=0; i< move_plans.length();i++){
        if(move_plans.at(i)=='R'){
                if(current_Y+1<N){
                    current_Y+=1;
                }
        }
        else if(move_plans.at(i)=='U'){
                if(current_X-1>=0){
                    current_X-=1;
                }
        }
        else if(move_plans.at(i)=='D'){
                if(current_X+1<N){
                    current_X+=1;
                }
        }
        else if(move_plans.at(i)=='L'){
                if(current_Y-1>=0){
                    current_Y-=1;
                }
        }
    }
    cout<<current_X+1<<' '<<current_Y+1<<'\n';   
    
}