#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x){

	string num = to_string(x);
	int size = num.size();

	for(int i=0,j=size-1; i<size/2; i++, j--){

		if(num[i] != num[j]){

			return false;

		}

	}

	return true;
}

int main()
{

	int x;
	cin>>x;
	cout<< isPalindrome(x) << endl;
	return 0;

}