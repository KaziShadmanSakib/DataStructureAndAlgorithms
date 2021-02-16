/*I have used Bellman Ford's Algorithm to solve this problem*/
/*Complexity O(VE)*/
#include<bits/stdc++.h>
using namespace std;
#define inf 1e6+1
struct node{
	int u,v,w;
	node(){}
	node(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector<node> edgeList;
int V,e;
long long cost[105];
int previ[105];
bool bellmanFord(int source){
	for(int i=0;i<V;i++){
		cost[i] = inf;
		previ[i] = -1;
	}
	cost[source] = 0;
	for(int i=1;i<=V-1;i++){
		for(int j=0;j<e;j++){
			int u = edgeList[j].u;
			int v = edgeList[j].v;
			int w = edgeList[j].w;
			if(cost[v] > cost[u] + w){
				cost[v] = cost[u] + w;
				previ[v] = u;
			}
		}
	}
	for(int i=0;i<e;i++){
		int u = edgeList[i].u;
		int v = edgeList[i].v;
		int w = edgeList[i].w;
		if(cost[v] > cost[u] + w){
			return false;
		}
	}
	return true;
}
int main()
{
	cout<< "Input" << endl;
	cout<< "-----" << endl;
	cin>>V>>e;
	edgeList.clear();
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edgeList.push_back(node(u,v,w));
	}
	cout<< endl;
	cout<< "Output" << endl;
	cout<< "------" << endl;
	if(not bellmanFord(0)){
		cout<< "Yes" << endl;
	}
	else{
		cout<< "No" << endl;
	}
	return 0;
}