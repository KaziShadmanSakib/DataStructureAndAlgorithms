#include<bits/stdc++.h>
using namespace std;

const int MAX_NODE = (int) 1e4+5;

#define notVis 0
#define vis 1

vector<int> adjList[MAX_NODE];
vector<int> order;
int visited[MAX_NODE];

void initiate(int n){
  order.clear();
  for(int i=1;i<=n;i++){
    adjList[i].clear();
  }
}

void input(int m){
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
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
  for(int v : adjList[source]){
    if(not visited[v]){
      dfs2(v);
    }
  }
}

int dfsOnGT(int n){
  int component = 0;
  for(int i=1;i<=n;i++){
    visited[i] = notVis;
  }
  reverse(order.begin(),order.end());
  for(int i=0;i<order.size();i++){
    int v = order[i];
    if(not visited[v]){
      dfs2(v);
      component++;
    }
  }
  return component;
}

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    int n,m;
    cin>>n>>m;
    initiate(n);
    input(m);
    dfsOnList(n);
    int res = dfsOnGT(n);
    cout<< "Case " << ++i << ": " << res << endl;
  }
  return 0;
}