#include<bits/stdc++.h>
using namespace std;
#define white 0
#define black 1
#define red 2
#define inf INT_MAX
vector<int> adjList[1000];
int color[1000];
int previ[1000];
int v,e;
bool flag = true;
void bfs(int s){
	color[s] = black;
	queue<int> q;
	q.push(s);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adjList[u]){
			if(color[v] == white && color[u] ==  black){
				color[v] = red;
				previ[v] = u;
				q.push(v);
			}
			if(color[v] == white && color[u] == red){
				color[v] = black;
				previ[v] = u;
				q.push(v);
			}
			if(color[v] == red && color[u] == red){
				flag = false;
				break;
			}
			if(color[v] == black && color[u] == black){
				flag = false;
				break;
			}
			else{
				flag = true;
			}
		}
	}
}
int main()
{
	while(1){
		cin>>v;
		if(v==0){
			break;
		}
		for(int i=0;i<v;i++){
			adjList[i].clear();
		}
		cin>>e;
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		memset(color,white,sizeof(color));
		memset(previ,-1,sizeof(previ));
		bfs(0);
		if(flag == true){
			cout<< "BICOLORABLE." <<endl;
		}
		else{
			cout<< "NOT BICOLORABLE." <<endl;
		}
	}
	return 0;
}