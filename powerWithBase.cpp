#include<bits/stdc++.h>
using namespace std;

int power(int base, int n){

	if(n == 1){

		return base;

	}

	return base * power(base, n-1);

}

int main()
{

	int base,n;

	cin>> base >> n;

	int ans = power(base, n);

	cout<< ans << endl;

	return 0;

}