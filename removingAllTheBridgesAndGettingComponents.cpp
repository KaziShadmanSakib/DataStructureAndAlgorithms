/*I have first tried to find all the bridges the adjList.
Then in newGraph, a newGraph has been made removing all the bridges from adjList*/
/*Used dfs to travese the newGraph and find components. Then the ans is the ceil of components leaf/2*/
#include<bits/stdc++.h>
using namespace std;
#define notVis 0
#define vis 1
#define inf INT_MAX
vector<pair<int,int>> bridges;
set<int>newGraph[1000005];
vector<int> adjList[1000005];
int visited[1000005];
int previ[1000005];
int disc[1000005];
int low[1000005];
int V,e,t;
vector<int> components[10000005];
void dfsVisit1(int source){
    visited[source] = vis;
    t = t + 1;
    disc[source] = t;
    low[source] = disc[source];
    for(int v : adjList[source]){
        if(not visited[v]){
            previ[v] = source;
            dfsVisit1(v);
            if(low[v] > disc[source]){
                bridges.push_back(make_pair(source,v));
                newGraph[source].erase(v);
                newGraph[v].erase(source);
            }
            low[source] = min(low[source],low[v]);
        }
        else if(previ[source]!=v){
            low[source] = min(disc[v],low[source]);
        }
    }
}
void bridge(){
    for(int i=0;i<V;i++){
        previ[i] = -1;
        visited[i] = notVis;
        disc[i] = inf;
        low[i] = inf;
    }
    t = 0;
    for(int i=0;i<V;i++){
        if(not visited[i]){
            dfsVisit1(i);
        }
    }
}
void dfsVisit2(int source){
    visited[source] = vis;
    for(int v : newGraph[source]){
        if(not visited[v]){
            dfsVisit2(v);
        }
    }
}
/*I don't even know what i did here*/
/*thank you for reading </3*/ 
int dfs(){
    for(int i=0;i<V;i++){
        previ[i] = -1;
        visited[i] = notVis;
    }
    int scc = 0;
    for(int i=0;i<V;i++){
        if(not visited[i]){
            dfsVisit2(i);
            scc++;
        }
    }
    int ans;
    ans = ceil(double(scc/2));
    return ans;
}
int main()
{
    cin>>V>>e;
    bridges.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        newGraph[u].insert(v);
        newGraph[v].insert(u);
    }
    bridge();
    int ans = dfs();
    cout<< ans << endl;
    bridges.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    return 0;
}