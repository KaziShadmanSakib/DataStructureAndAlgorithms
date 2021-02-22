#include<bits/stdc++.h>
using namespace std;

#define notVis 0
#define vis 1
#define inf INT_MAX

const int MAX_NODE = (int) 1e4+5;

vector<int> adjList[MAX_NODE];
bool hills[MAX_NODE];
int visited[MAX_NODE];
int previ[MAX_NODE];
int disc[MAX_NODE];
int low[MAX_NODE];
int t;

void initialize(int n){
  for(int i=1;i<=n;i++){
    hills[i] = false;
    previ[i] = -1;
    visited[i] = notVis;
    disc[i] = inf;
    low[i] = inf;
  }
}

void input(int m){
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

void dfsVisit(int source){
  int children = 0;
  visited[source] = vis;
  t = t + 1;
  disc[source] = t;
  low[source] = disc[source];
  for(int v : adjList[source]){
    if(not visited[v]){
      children++;
      previ[v] = source;
      dfsVisit(v);
      if(previ[source] == -1 && children > 1){
        hills[source] = true;
      }
      if(previ[source] != -1 && low[v] >= disc[source]){
        hills[source] = true;
      }
      low[source] = min(low[v],low[source]);
    }
    else if(previ[source] != v){
      low[source] = min(disc[v],low[source]);
    }
  }
}

int totalAntHillsToFire(int n){
  t = 0;
  int res = 0;
  for(int i=1;i<=n;i++){
    if(not visited[i]){
      dfsVisit(i);
    }
  }
  for(int i=1;i<=n;i++){
    if(hills[i]){
      res++;
    }
  }
  return res;
}

void vectorClear(int n){
  for(int i=1;i<=n;i++){
    adjList[i].clear();
  }
}

int main()
{
  int testCase,i=0;
  cin>>testCase;
  while(testCase--){
    int n,m;
    cin>>n>>m;
    initialize(n);
    input(m);
    int res = totalAntHillsToFire(n);
    cout<< "Case " << ++i << ": " << res << endl;
    vectorClear(n);
  }
  return 0;
}