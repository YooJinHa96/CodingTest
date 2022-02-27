#include <string>
#include <vector>

using namespace std;

int ans=0;
void DFS(vector<int> & numbers, int & target,int index,int sum){

    if(index==numbers.size()){
        if(sum==target)
            ans=ans+1;
    }
    else
    {
        DFS(numbers,target, index+1, sum + numbers[index]*1);
        DFS(numbers,target, index+1,sum + numbers[index]*-1);
    }   

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    

    DFS(numbers,target, 1, numbers[0]*1);
    DFS(numbers,target, 1, numbers[0]*-1);

    answer=ans;
    return answer;
}