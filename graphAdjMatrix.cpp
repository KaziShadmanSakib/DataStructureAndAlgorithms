#include<bits/stdc++.h>
using namespace std;
int main()
{
	int adjMatrx[100][100];
	memset(adjMatrx,0,sizeof(adjMatrx));
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjMatrx[u][v] = 1;
		//adjMatrx[v][u] = 1; /*undirected graph*/
	}
	/*Is there a direct link between A and B*/
	int A,B;
	cin>>A>>B;
	if(adjMatrx[A][B]==1 || adjMatrx[A][B]==1){
		cout<<"Yes there is a direct link between A and B"<<endl;
	}
	else{
		cout<<"No, there is no direct link between A and B"<<endl;
	}
	/*What is the indegree for a vertex A*/
	int indegree = 0;
	for(int i=0;i<v;i++){
		if(adjMatrx[i][A]==1){
			indegree++;
		}
	}
	cout<<indegree<<endl;
	/*What is the outdegree for a vertex A*/
	int outdegree = 0;
	for(int i=0;i<v;i++){
		if(adjMatrx[A][i]==1){
			outdegree++;
		}
	}
	cout<<outdegree<<endl;
	/*How many nodes are directly connected to vertex A*/
	int totalNodes = indegree + outdegree;
	cout<<totalNodes<<endl;
	return 0;
}