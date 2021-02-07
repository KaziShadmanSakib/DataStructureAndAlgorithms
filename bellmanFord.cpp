#include<bits/stdc++.h>
using namespace std;
#define inf 1e6
struct node{
	int v,w;
	node(){}
	node(int v,int w){
		this->v = v;
		this->w = w;
	}
};
vector<node> adjList[105];
int d[105];
int previ[105];
int v,e;
bool bellmanFord(int source){
	for(int i=0;i<v;i++){
		d[i] = inf;
		previ[i] = -1;
	}
	d[source] = 0;
	for(int i=1;i<=v-1;i++){
		for(int u=0;u<e;u++){
			for(int j=0;j<adjList[u].size();j++){
				int v = adjList[u][j].v;
				int w = adjList[u][j].w;
				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
					previ[v] = u;
				}
			}
		}
	}
	for(int u=0;u<e;u++){
		for(int j=0;j<adjList[u].size();j++){
			int v = adjList[u][j].v;
			int w = adjList[u][j].w;
			if(d[v]>d[u] + w){
				return false;
			}
		}
	}
	return true;
}
void printPath(int source,int destination){
	if(destination==source){
		cout<< source << " Cost-> " << d[source] << endl;
	}
	else if(previ[destination]==-1){
		cout<<"There is no path"<<endl;
	}
	else{
		printPath(source,previ[destination]);
		cout<< destination << " Cost-> " << d[destination] << endl;
	}
}
int main()
{
	cin>>v>>e;
	for(int i=0;i<v;i++){
		adjList[i].clear();
	}
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adjList[u].push_back(node(v,w));
	}
	int source,destination;
	cin>>source;
	cin>>destination;
	bool x = bellmanFord(source);
	if(x==false){
		cout<< "Negative Cycle Found" <<endl;
	}
	else{
		printPath(source,destination);
	}
	return 0;
}