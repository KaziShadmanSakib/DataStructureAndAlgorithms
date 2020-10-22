#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,prev=0,now=1;
	scanf("%d",&x);
	for(int i=0;i<=x;i++){
		if(i<2){
			printf("%d ",i);
		}
		else{
			int temp=now;
			now = now+prev;
			prev = temp;
			printf("%d ",now);
		}
	}
	printf("\n");
	return 0;
}