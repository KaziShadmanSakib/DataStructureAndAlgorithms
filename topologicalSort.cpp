#include<bits/stdc++.h>
using namespace std;
#define vis 1
#define notVis 0
vector<int> adjList[105];
int visited[105];
int previ[105];
int V,e;
vector<int> path;
void dfsVisit(int source){
    visited[source] = vis;
    for(int v : adjList[source]){
        if(not visited[v]){
            previ[v] = source;
            dfsVisit(v);
        }
    }
    path.push_back(source);
}
void dfs(){
    for(int i=1;i<=V;i++){
        visited[i] = notVis;
        previ[i] = -1;
    }
    for(int i=1;i<=V;i++){
        if(not visited[i]){
            dfsVisit(i);
        }
    }
}
int main()
{
    while(1){
        cin>>V>>e;
        if(V==0 && e==0){
            break;
        }
        for(int i=1;i<=V;i++){
            adjList[i].clear();
        }
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adjList[u].push_back(v);
        }
        dfs();
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<< path[i];
            i == path.size()-1 ? cout<< endl : cout<< " ";
        }
        path.clear();
        for(int i=1;i<=V;i++){
            adjList[i].clear();
        }
    }
    return 0;
}