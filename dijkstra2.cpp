/*Solving this problem using Dijkstra's Algorithm (Single Source Shortest Path Algorithm)*/
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
		return w>a.w || (w == a.w && v>a.v);
	}
};
vector<node> adjList[100005];
int previ[100005];
int minCost[100005];
int n,m;
/*Function that implements Dijkstra's single source shortest path algorithm 
  for a graph represented using adjacency list representation*/
void dijkstra(int source){
	/*Initializing*/
	for(int i=0;i<n;i++){
		previ[i] = -1;
		minCost[i] = inf;
	}
	/*The cost of source vertex from itself is always 0*/
	minCost[source] = 0;
	/*Using priority queue to use the speciality of min heap data structure*/
	priority_queue<node> prioQ;
	prioQ.push(node(source,minCost[source]));
	while(not prioQ.empty()){
		int u = prioQ.top().v;
		prioQ.pop();
		for(int i=0;i<adjList[u].size();i++){
			int vertex = adjList[u][i].v;
			int weight = adjList[u][i].w;
			if(minCost[vertex]>minCost[u]+weight){
				minCost[vertex] = minCost[u] + weight;
				previ[vertex] = u;
				prioQ.push(node(vertex,minCost[vertex]));
			}
		}
	}
}
/*Made a recursive funtion to print the shortest path from node 0 (source) to node 1 (destination)*/
/*Later on we will call this funtion to print path from node 0 (source) to node 1 (destination)*/
void printPath(int source,int destination){
	if(destination == source){
		cout<< source << " ";
	}
	else if(previ[destination]==-1){
		cout<< "Not Reachable";
	}
	else{
		printPath(source,previ[destination]);
		cout<< destination << " ";
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		adjList[i].clear();
	}
	/*defines an edge between U and V with weight W*/
	/*Also the graph is undirected*/
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adjList[u].push_back(node(v,w));
		adjList[v].push_back(node(u,w));
	}
	/*Calling the function dijkstra by giving the node 0 as source value*/
	dijkstra(0);
	/*Calling the printPath function to print the shortest path from node 0 (source) to node 1 (destination)*/
	printPath(0,1);
	cout<<endl;
	return 0;
}