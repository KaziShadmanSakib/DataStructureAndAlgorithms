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
		return w > a.w || (w==a.w && v > a.v);
	}
};
vector<node> adjList[105];
int previ[105];
int d[105];
int v,e;
void dijkstra(int s){
	for(int i=0;i<v;i++){
		previ[i] = -1;
		d[i] = inf;
	}
	priority_queue<node> q;
	d[s] = 0;
	q.push(node(s,d[s]));
	while(not q.empty()){
		int u = q.top().v;
		q.pop();
		for(int i=0;i<adjList[u].size();i++){
			int v = adjList[u][i].v;
			int w = adjList[u][i].w;
			if(d[v] > d[u] + w){
				previ[v] = u;
				d[v] = d[u] + w;
				q.push(node(v,d[v]));
			}
		}
	}
}
void printPath(int source,int destination){
	if(destination == source){
		cout<< source << " The cost is " << d[source] <<endl;
	}
	else if(previ[destination]==-1){
		cout<<"There is no path" <<endl;
	}
	else{
		printPath(source,previ[destination]);
		cout<< destination << " The cost is " << d[destination] <<endl;
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
	int s,d;
	cout<<"Enter Source: ";
	cin>>s;
	cout<<"Enter Destination: ";
	cin>>d;
	dijkstra(s);
	printPath(s,d);
	return 0;
}