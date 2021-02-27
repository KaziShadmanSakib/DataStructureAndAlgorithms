#include<bits/stdc++.h>
using namespace std;

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int x1,y1,x2,y2;
    cin>> x1 >> y1 >> x2 >> y2;
    int m;
    cin>> m;
    cout<< "Case " << ++i << ":" << endl;
    while(m--){
      int x,y;
      cin>> x>> y;
      x < x1 || y < y1 || x > x2 || y > y2 ? cout<< "No" << endl : cout << "Yes" << endl;
    }
  }
  return 0;
}