#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
struct node{
	int v,w;
	node(){}
	node(int v, int w){
		this->v = v;
		this->w = w;
	}
	bool operator <(const node &a)const{
		return w > a.w || (w == a.w && v>a.v);
	}
};
vector<node> adjList[1005];
int cost[1005];
int previ[1005];
int cnt[1005];
int V,e;
bool dijkstra(int source){
	for(int i=0;i<V;i++){
		cost[i] = inf;
		previ[i] = -1;
		cnt[i] = 0;
	}
	cost[source] = 0;
	priority_queue<node> q;
	q.push(node(source,cost[source]));
	while(not q.empty()){
		int u = q.top().v;
		q.pop();
		for(int i=0;i<adjList[u].size();i++){
			int v = adjList[u][i].v;
			int w = adjList[u][i].w;
			if(cost[v] > cost[u] + w){
				cost[v] = cost[u] + w;
				previ[v] = u;
				q.push(node(v,cost[v]));
				cnt[v]++;
				if(cnt[v]>=V){
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>V>>e;
		for(int i=0;i<V;i++){
			adjList[i].clear();
		}
		for(int i=0;i<e;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adjList[u].push_back(node(v,w));
		}
		if(dijkstra(0)==true){
			cout<< "possible" <<endl;
		}
		else{
			cout<< "not possible" <<endl;
		}
	}
	return 0;
}