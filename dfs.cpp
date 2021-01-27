#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
int color[1000]; /*color = 0 is white, color = 1 is gray, color = 2 is black*/
int previ[1000];
int t,v,e;
int d[1000];
int f[1000];
void DFS_Visit(int u){
	cout<<u<<" ";
	color[u] = 1;
	t = t + 1;
	d[u] = t;
	for(int v : adjList[u]){
		if(color[v]==0){
			previ[v] = u;
			DFS_Visit(v);
		}
	}
	color[u] = 2;
	t = t + 1;
	f[u] = t;
}
void DFS(int s){
	t = 0;
	for(int i=s;i<v;i++){
		if(color[i]==0){
			DFS_Visit(i);
		}
	}
}
int main()
{
	cin>>v>>e;
	for(int i=0;i<v;i++){
		adjList[i].clear();
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
	}
	memset(color,0,sizeof(color));
	memset(previ,-1,sizeof(previ));
	memset(d,INT_MAX,sizeof(d));
	memset(f,INT_MAX,sizeof(f));
	int s;
	cin>>s;
	DFS(s);
	cout<<endl;
	return 0;
}