/*Solving this problem using Floyd-Warshall's Algorithm (All Pair Shortest Path Algorithm)*/
#include<bits/stdc++.h>
using namespace std;
#define inf 1000001
int n,m;
/*Function that implements Floyd-Warshall's all pair shortest path algorithm 
  for a graph represented using adjacency matrix representation*/
void floydWarshall(int adjMatrix[][105]){
	int minCost[n][n];
	/*Initializing*/ 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			minCost[i][j] = adjMatrix[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(minCost[i][j]>minCost[i][k]+minCost[k][j]){
					minCost[i][j] = minCost[i][k] + minCost[k][j];
				}
			}
		}
	}
	/*Prints the shortest distance of every pair*/ 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>j){
				continue;
			}
			if(minCost[i][j]==inf){
				cout<<  i << " to " << j << ": " << "No Path" <<endl;
			}
			else if(i==j){
				continue;
			}
			else{
				cout<< i << " to " << j << ": " << minCost[i][j] <<endl;
			}
		}
	}
}
int main()
{
	int adjMatrix[105][105];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				adjMatrix[i][j] = 0;
			}
			else{
				adjMatrix[i][j] = inf;
			}
		}
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		/*defines an edge between U and V with weight W*/
		/*Also the graph is undirected*/
		adjMatrix[u][v] = min(adjMatrix[u][v],w);
		adjMatrix[v][u] = min(adjMatrix[v][u],w);
	}
	/*Calling the function floydWarshall by giving the adjMatrix*/
	floydWarshall(adjMatrix);
	return 0;
}