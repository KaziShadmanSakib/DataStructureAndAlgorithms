#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
bool visited[1000];
void bfs(int s){
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while(not q.empty()){
		int u = q.front();
		cout<< u << " ";
		q.pop();
		for(int v : adjList[u]){
			if(not visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<=v;i++){
		adjList[i].clear();
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjList[u].push_back(v);
	}
	memset(visited,false,sizeof(visited));
	int s;
	cin>>s;
	bfs(s);
	cout<<endl;
	return 0;
}