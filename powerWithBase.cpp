#include<bits/stdc++.h>
using namespace std;

int factorial(int base, int n){

	if(n == 1){

		return base;

	}

	return base * factorial(base, n-1);

}

int main()
{

	int base,n;

	cin>> base >> n;

	int ans = factorial(base, n);

	cout<< ans << endl;

	return 0;

}