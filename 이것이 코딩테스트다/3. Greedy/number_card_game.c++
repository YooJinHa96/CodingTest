#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int min=10000;
    int max=0;
    for(int i=0;i<N;i++)
    {
        min=10000;
        for(int j=0;j<M;j++){
            int num;
            cin>>num;
            if(min> num ){
                min = num;
            }
        }
        if(max<min){
            max=min;
        }
    }
    cout<< max<<"\n";   

}