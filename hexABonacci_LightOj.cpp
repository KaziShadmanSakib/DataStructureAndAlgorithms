#include<bits/stdc++.h>
using namespace std;

long long dp[10005];
long long a,b,c,d,e,f,n;

long long fib(long long n){
  if(n==0){
    return a % 10000007;
  }
  if(n==1){
    return b % 10000007;
  }
  if(n==2){
    return c % 10000007;
  }
  if(n==3){
    return d % 10000007;
  }
  if(n==4){
    return e % 10000007;
  }
  if(n==5){
    return f % 10000007;
  }
  if(dp[n]==-1){
    dp[n] = fib(n-1) + fib(n-2) + fib(n-3)+ fib(n-4)+ fib(n-5) + fib(n-6);
  }
  return dp[n] % 10000007;
}

int main()
{
  int testCase,i=0;
  cin>>testCase;
  while(testCase--){
    cin>>a>>b>>c>>d>>e>>f>>n;
    memset(dp,-1,sizeof(dp));
    long long res = fib(n);
    cout<< "Case " << ++i << ": " << res << endl;
  }
  return 0;
}