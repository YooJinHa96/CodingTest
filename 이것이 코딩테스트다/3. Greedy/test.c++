#include <iostream>
using namespace std;

int main(){
   int n = 1250;
   int count =0 ;
   int coin[4]={500,100,50,100};

   for (int i=0 ; i<4 ; i++){
      count += n / coin[i];
      n %= coin[i];
   }

   cout << count<< "\n";
}


