/*I have used Topological Sort to solve this problem.*/
/*Topological Sort of a directed acyclic graph G = (V,E) :
  a linear order of vertices such that if there exists an edge (u,v),
  then u appears before v in the ordering.*/
/*Time Complexity O(V+E)*/
#include<bits/stdc++.h>
using namespace std;
#define notVis 0
#define vis 1
vector<int> adjList[1000005];
vector<int> order;
int V,e;
int visited[1000005];
void dfs(int source){
    visited[source] = vis;
    for(int v : adjList[source]){
        if(not visited[v]){
            dfs(v);
        }
    }
    order.push_back(source);
}
void topSort(){
    for(int i=0;i<V;i++){
        visited[i] = notVis;
    }
    for(int i=0;i<V;i++){
        if(not visited[i]){
            dfs(i);
        }
    }
    reverse(order.begin(),order.end());
}
int main()
{
    cin>>V>>e;
    order.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    topSort();
    for(int i=0;i<V;i++){
        cout<< order[i] << endl;
    }
    order.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    return 0;
}