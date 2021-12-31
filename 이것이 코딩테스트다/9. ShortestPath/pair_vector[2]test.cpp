/*

    vector 2차원 pair test

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    vector<vector<pair<int,int>>> a;
    vector<pair<int,int>> p;


    a.push_back(p);
    a.push_back(p);
    a[1].push_back(make_pair(1,2));
    a[1].push_back(make_pair(3,4));
    cout<<a[1][0].first<<' '<<a[1].front().second<<'\n';

}
