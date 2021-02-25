#include<bits/stdc++.h>
using namespace std;
int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int a,b,c;
    cin>> a>> b >> c;
    ((a*a)+(b*b)) == (c*c) || ((b*b)+(c*c)) == (a*a) || ((a*a)+(c*c)) == (b*b) ?
    cout<< "Case " << ++i << ": yes" << endl 
    : cout << "Case " << ++i << ": no" << endl;
  }
  return 0;
}