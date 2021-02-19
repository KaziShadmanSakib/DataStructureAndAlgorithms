/*A node when deleted along with any adjoining arcs, would split the graph
  into two or more seperated connected compononets is called an Articulation Point*/
/*A node will be an Articulation Point for two reasons:
  1) If node u is root of DFS tree and has atleast 2 children (subgraph)
  2) If node u is not root of DFS tree and it has a child v such that no vertex
     in subtree rooted with v has a back-edge to one of the ancestors of u*/
/*Time Complexity O(V+E)*/
#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define inf INT_MAX
vector<int> adjList[1000005];
bool aP[1000005];
int V,e,t;
int color[1000005];
int previ[1000005];
int disc[1000005];
int finish[1000005];
int low[1000005];
void dfsVisit(int source){
    int children = 0;
    color[source] = gray;
    t = t + 1;
    disc[source] = t;
    low[source] = disc[source];
    for(int v : adjList[source]){
        if(color[v]==white){
            children++;
            previ[v] = source;
            dfsVisit(v);
            if(previ[source]==-1 && children>1){
                aP[source] = true;
            }
            if(previ[source]!=-1 && low[v]>=disc[source]){
                aP[source] = true;
            }
            low[source] = min(low[source],low[v]);
        }
        else if(previ[source]!=v){
            low[source] = min(disc[v],low[source]);
        }
    }
    color[source] = black;
    t = t + 1;
    finish[source] = t;
}
void articulationPoints(){
    for(int i=0;i<V;i++){
        aP[i] = false;
        color[i] = white;
        previ[i] = -1;
        disc[i] = inf;
        finish[i] = inf;
        low[i] = inf;
    }
    t = 0;
    for(int i=0;i<V;i++){
        if(color[i]==white){
            dfsVisit(i);
        }
    }
}
void printArticulationPoints(){
    for(int i=0;i<V;i++){
        if(aP[i]==true){
            cout<< i << endl;
        }
    }
}
int main()
{
    cin>>V>>e;
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    articulationPoints();
    printArticulationPoints();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    return 0;
}