#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2
#define inf INT_MAX
vector<int> adjList[1000];
int color[1000];
int previ[1000];
int d[1000];
int f[1000];
int v,e,t;
void dfsVisit(int u){
	cout<< u << " ";
	color[u] = grey;
	t = t + 1;
	d[u] = t;
	for(int v : adjList[u]){
		if(color[v]==white){
			previ[v] = u;
			dfsVisit(v);
		}
	}
	color[u] = black;
	t = t + 1;
	f[u] = t;
}
void dfs(int s){
	t = 0;
	for(int i=s;i<v;i++){
		if(color[i]==white){
			dfsVisit(i);
		}
	}
}
void printPath(int source, int destination){
	if(destination == source){
		cout<< source << " ";
	}
	else if(previ[destination]==-1){
		cout<< "No task is there" << endl;
	}
	else{
		printPath(source,previ[destination]);
	}
}
int main()
{
	cin>>v>>e;
	for(int i=0;i<=v;i++){
		adjList[i].clear();
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
	}
	memset(color,white,sizeof(color));
	memset(previ,-1,sizeof(previ));
	memset(d,inf,sizeof(d));
	memset(f,inf,sizeof(f));
	int s;
	cin>>s;
	dfs(s);

	cout<<endl;
	return 0;
}