#include<bits/stdc++.h>
using namespace std;
#define inf 1e5
struct node{
	int u,v,w;
	node(){}
	node(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector<node> graph;
int V,e;
int d[105];
int previ[105];
bool bellmanFord(int source){
	for(int i=0;i<V;i++){
		d[i] = inf;
		previ[i] = -1;
	}
	d[source] = 0;
	for(int i=1;i<=V-1;i++){
		for(int j=0;j<e;j++){
			int u = graph[j].u;
			int v = graph[j].v;
			int w = graph[j].w;
			if(d[u]+w < d[v]){
				d[v] = d[u] + w;
				previ[v] = u;
			}
		}
	}
	for(int i=0;i<e;i++){
		int u = graph[i].u;
		int v = graph[i].v;
		int w = graph[i].w;
		if(d[v] > d[u]+w){
			return false;
		}
	}
	return true;
}
void printPath(int source,int destination){
	if(destination==source){
		cout<< source << " Cost-> " << d[source] << endl;
	}
	else if(previ[destination]==-1){
		cout<< "No Path Found" << endl;
	}
	else{
		printPath(source,previ[destination]);
		cout<< destination << " Cost-> " << d[destination] << endl;
	}
}
int main()
{
	cin>>V>>e;
	for(int i=0;i<V;i++){
		graph.clear();
	}
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph.push_back(node(u,v,w));
	}
	int source,destination;
	cin>>source>>destination;
	if(bellmanFord(source)==false){
		cout<< "Negative Cycle Found";
	}
	else{
		printPath(source,destination);
	}
	return 0;
}