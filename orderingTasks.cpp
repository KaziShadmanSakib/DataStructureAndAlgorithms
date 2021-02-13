#include<bits/stdc++.h>
using namespace std;
#define notExecuted 0
#define executed 1
vector<int> adjList[105];
stack<int> s;
int V,e;
int work[105];
int previ[105];
void dfsVisit(int u){
	work[u] = executed;
	for(int v : adjList[u]){
		if(work[v]==notExecuted){
			dfsVisit(v);
		}
	}
	s.push(u);
}
void dfs(){
	for(int i=1;i<=V;i++){
		previ[i] = -1;
		work[i] = notExecuted;
	}
	for(int i=1;i<=V;i++){
		if(work[i] == notExecuted){
			dfsVisit(i);
		}
	}
}
int main()
{
	while(1){
		cin>>V>>e;
		if(V==0 && e==0){
			break;
		}
		for(int i=1;i<=V;i++){
			adjList[i].clear();
		}
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			adjList[u].push_back(v);
		}
		dfs();
		while(not s.empty()){
			cout<< s.top() << " ";
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}