#include<bits/stdc++.h>
using namespace std;
#define white 0
#define grey 1
#define black 2
#define inf INT_MAX
vector<int> adjList[1000];
int v,e;
int color[1000];
int previ[1000];
int d[1000];
void bfs(int s){
	color[s] =  grey;
	d[s] = 0;
	previ[s] = -1;
	queue<int> q;
	q.push(s);
	while(not q.empty()){
		int u = q.front();
		cout<< u << " ";
		q.pop();
		for(int v : adjList[u]){
			if(color[v]==white){
				color[v] = grey;
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
	int s;
	cin>>s;
	bfs(s);
	cout<<endl;
	return 0;
}