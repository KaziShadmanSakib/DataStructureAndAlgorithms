#include<bits/stdc++.h>
using namespace std;

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int n,res=0;
    cin>> n;
    while(n--){
      int dustUnit;
      cin>> dustUnit;
      if(dustUnit<1){
        continue;
      }
      else{
        res = res + dustUnit;
      }
    }
    cout<< "Case " << ++i << ": " << res << endl;
  }
  return 0;
}