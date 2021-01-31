#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define inf INT_MAX
vector<int> adjList[1005];
int color[1005];
int previ[1005];
int d[1005];
int v,e;
void bfs(int s){
	for(int i=0;i<v;i++){
		color[i] = white;
		previ[i] = -1;
		d[i] = inf;
	}
	color[s] = gray;
	previ[s] = -1;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adjList[u]){
			if(color[v]==white){
				color[v] = gray;
				previ[v] = u;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
		color[u] = black;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>v>>e;
		for(int i=0;i<v;i++){
			adjList[i].clear();
		}
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		bfs(0);
		for(int i=1;i<v;i++){
			cout<< d[i] << endl;
		}
		if(t>0){
			cout<<endl;
		}
	}
	return 0;
}