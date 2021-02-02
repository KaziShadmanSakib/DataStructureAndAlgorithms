#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
struct node{
	int v,w;
	node(){}
	node(int v,int w){
		this->v = v;
		this->w = w;
 	}
 	bool operator <(const node &a)const{
 		return w > a.w || (w==a.w && v> a.v);
 	}
};
vector<node> adjList[105];
int previ[105];
int d[105];
int v,e;
void dijkstra(int s){
	for(int i=1;i<=v;i++){
		previ[i] = -1;
		d[i] = inf;
	}
	d[s] = 0;
	priority_queue<node> q;
	q.push(node(s,d[s]));
	while(not q.empty()){
		int u = q.top().v;
		q.pop();
		for(int i=0;i<adjList[u].size();i++){
			int v = adjList[u][i].v;
			int w = adjList[u][i].w;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				previ[v] = u;
				q.push(node(v,d[v]));
			}
		}
	}
}
int main()
{
	int testCase,i=0;
	cin>>testCase;
	while(testCase--){
		cin>>v>>e;
		for(int i=1;i<=v;i++){
			adjList[i].clear();
		}
		for(int i=0;i<e;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adjList[u].push_back(node(v,w));
			adjList[v].push_back(node(u,w));
		}
		dijkstra(1);
		if(d[v]==inf){
			cout<< "Case " << ++i << ": Impossible" << endl; 
		}
		else{
			cout<< "Case " << ++i << ": " << d[v] << endl;
		}
	}
	return 0;
}