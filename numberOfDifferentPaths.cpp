/*I have used Floyd-Warshall's Algorithm to solve this problem*/
/*Complexity O(V^3)*/
#include<bits/stdc++.h>
using namespace std;
int adjMatrix[105][105];
int V,e;
void floydWarshall(){
	int totalPaths[105][105];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			totalPaths[i][j] = adjMatrix[i][j];
		}
	}
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				totalPaths[i][j] = totalPaths[i][j] + (totalPaths[i][k]*totalPaths[k][j]);
			}
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i==j){
				continue;
			}
			else{
				cout << "Number of paths from " << i << " to " << j << ": " << totalPaths[i][j] << endl;
			}
		}
	}
}
int main()
{
	cout<< "Input" << endl;
	cout<< "-----" << endl;
	cin>>V>>e;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjMatrix[u][v] = adjMatrix[u][v] + 1;
	}
	cout<< "Output" << endl;
	cout<< "------" << endl;
	floydWarshall();
	return 0;
}