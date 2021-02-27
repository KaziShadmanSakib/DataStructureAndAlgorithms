#include<bits/stdc++.h>
using namespace std;

bool palindromeOrNot(string s){
  for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
    if(s[i]!=s[j]){
      return false;
    }
  }
  return true;
}

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    string s;
    cin>> s;
    palindromeOrNot(s) ? 
    cout << "Case " << ++i << ": Yes" << endl:
    cout << "Case " << ++i << ": No" << endl;
  }
  return 0;
}