#include<bits/stdc++.h>
using namespace std;

int findDigits(int n,int b){
  if(n < 0){
    return 0;
  }
  if(n<1){
    return 1;
  }
  double x = ((n * log10(n/M_E) +  log10(2 * M_PI * n) / 2.0)) / (log10(b));
  return floor(x)+1;
}

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int n,b;
    cin>> n >>b;
    int res = findDigits(n,b);
    cout << "Case " << ++i << ": " << res << endl; 
  }
  return 0;
}