#include<bits/stdc++.h>
using namespace std;

#define notVis 0
#define vis 1
#define inf INT_MAX

const int MAX_NODE = (int) 1e4+5;
vector<int> adjList[MAX_NODE];
vector<pair<int,int>> bridges;
int previ[MAX_NODE];
int disc[MAX_NODE];
int low[MAX_NODE];
int visited[MAX_NODE];
int t;

void dfsVisit(int source){
  visited[source] = vis;
  t = t + 1;
  disc[source] = t;
  low[source] = disc[source];
  for(int v : adjList[source]){
    if(not visited[v]){
      previ[v] = source;
      dfsVisit(v);
      if(low[v] > disc[source]){
        source > v ?
        bridges.push_back(make_pair(v,source)) 
        : bridges.push_back(make_pair(source,v));
      }
      low[source] = min(low[source],low[v]);
    }
    else if(previ[source]!=v){
      low[source] = min(disc[v],low[source]);
    }
  }
}

void bridge(int nTest){
  for(int i=0;i<nTest;i++){
    visited[i] = notVis;
    previ[i] = -1;
    disc[i] = inf;
    low[i] = inf;
  }
  t = 0;
  for(int i=0;i<nTest;i++){
    if(not visited[i]){
      dfsVisit(i);
    }
  }
}

void input(int nTest){
  while(nTest--){
    int u,edges;
    scanf("%d (%d)",&u,&edges);
    while(edges--){
      int v;
      scanf("%d",&v);
      adjList[u].push_back(v);
    }
  }
}

int main()
{
  int testCase,i=0;
  scanf("%d",&testCase);
  while(testCase--){
    int nTest;
    scanf("%d",&nTest);
    input(nTest);
    bridge(nTest);
    sort(bridges.begin(),bridges.end());
    cout<< "Case " << ++i << ":" << endl;
    cout<< bridges.size() << " critical links" << endl;
    for(int i=0;i<bridges.size();i++){
      cout<< bridges[i].first << " - " << bridges[i].second << endl;
    }
    bridges.clear();
    for(int i=0;i<nTest;i++){
      adjList[i].clear();
    }
  }
  return 0;
}