#include<bits/stdc++.h>
using namespace std;
int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int n,m,time = 0;
    cin>>n>>m;
    if(n<=m){
      while(1){
        if(m==0){
          time = time + 3 + 5;
          break;
        }
        if(m==n){
          time = time + 3 + 5 + 3;
        }
        m--;
        time = time + 4;
      }
      cout<< "Case " << ++i << ": " << time << endl;
    }
    else{
      while(n>=m){
        if(n==m){
          time = time + 3 + 5 + 3;
        }
        m++;
        time = time + 4;
      }
      while(1){
        if(m==0){
          time = time + 3 + 5;
          break;
        }
        m--;
        time = time + 4;
      }
      cout<< "Case " << ++i << ": " << time-8 << endl;
    }
  }
  return 0;
}