#include<bits/stdc++.h>
using namespace std;

#define notVis 0
#define vis 1

vector<int> adjList[2005];
vector<int> graphT[2005];
vector<int> order;
int visited[2005];

void initiate(int n){
  order.clear();
  for(int i=1;i<=n;i++){
    adjList[i].clear();
    graphT[i].clear();
  }
}

void input(int m){
  for(int i=0;i<m;i++){
    int u,v,p;
    cin>>u>>v>>p;
    if(p == 1){
      adjList[u].push_back(v);
      graphT[v].push_back(u);
    }
    else{
      adjList[u].push_back(v);
      adjList[v].push_back(u);
      graphT[v].push_back(u);
      graphT[u].push_back(v);
    }
  }
}

void dfs1(int source){
  visited[source] = vis;
  for(int v : adjList[source]){
    if(not visited[v]){
      dfs1(v);
    }
  }
  order.push_back(source);
}

void dfsOnList(int n){
  for(int i=1;i<=n;i++){
    visited[i] = notVis;
  }
  for(int i=1;i<=n;i++){
    if(not visited[i]){
      dfs1(i);
    }
  }
}

void dfs2(int source){
  visited[source] = vis;
  for(int v : graphT[source]){
    if(not visited[v]){
      dfs2(v);
    }
  }
}

int dfsOnGraphT(int n){
  int component = 0;
  for(int i=1;i<=n;i++){
    visited[i] = notVis;
  }
  for(int i=0;i<n;i++){
    int v = order[n-1-i];
    if(not visited[v]){
      dfs2(v);
      component++;
    }
  }
  return component;
}

int main()
{
  while(1){
    int n,m;
    cin>>n>>m;
    if(n == 0 && m == 0)
      break;
    initiate(n);
    input(m);
    dfsOnList(n);
    int res = dfsOnGraphT(n);
    res == 1 ? cout << "1" << endl : cout << "0" << endl; 
  }
  return 0;
}