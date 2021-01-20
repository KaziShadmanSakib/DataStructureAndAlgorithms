#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> adjList[100];
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
		// adjList[v].push_back(u); /*undirected graph*/
	}
	/*Is there a direct link between A and B ----> way01*/
	int A,B,found = 0;
	cin>>A>>B;
	for(int i=0;i<adjList[A].size();i++){
		int v = adjList[A][i];
		if(v == B){
			found = 1;
			break;
		}	
		else{
			found = 0;
		}
	}
	if(found==1){
		cout<<"Yes there is a direct link between A and B"<<endl;
	}
	else{
		cout<<"No, there is no direct link between A and B"<<endl;
	}
	/*What is the indegree for a vertex A*/
	int indegree = 0;
	for(int i=0;i<v;i++){
		for(int j=0;j<adjList[i].size();j++){
			int v = adjList[i][j];
			if(v == A){
				indegree++;
			}
		}
	}
	cout<<indegree<<endl;
	/*What is the outdegree for a vertex A*/
	int outdegree = adjList[A].size();
	cout<<outdegree<<endl;
	/*How many nodes are directly connected to vertex A*/
	int totalNodes = indegree+outdegree;  
	cout<<totalNodes<<endl;
	/*Is there a direct link between A and B ----> way02*/
	sort(adjList[A].begin(),adjList[A].end());
	if(binary_search(adjList[A].begin(),adjList[A].end(),B)){
		cout<<"Yes there is a direct link between A and B"<<endl;
	}
	else{
		cout<<"No, there is no direct link between A and B"<<endl;
	}
	return 0;
}