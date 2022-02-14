#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int weight = limit;
    sort(people.begin(), people.end());
    cout<<people[0]<<"\n";
    int i = 0;
    while (i < people.size())
    {

        if (weight >= people[i])
        {
            weight -= people[i];
            i++;
        }
        if (weight == 0)
        {
            answer++;
            i++;
            weight = limit;
            continue;
        }
        if(weight <people[i])
        {
         
            weight = limit;           
            answer++;
        }
    }
    if (weight != limit){
        answer++;
    }
    return answer;
}

int main(){
    int answer=solution({50,30,50,50},100);
    cout<<answer<<"\n";
}