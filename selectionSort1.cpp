#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int minIndex = i;
		for(int j=i+1;j<n;j++){
			if(a[minIndex]>a[j]){
				minIndex = j;
			}
		}
		swap(&a[i],&a[minIndex]);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}