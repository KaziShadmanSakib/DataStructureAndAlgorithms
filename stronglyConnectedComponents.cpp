#include<bits/stdc++.h>
using namespace std;
#define notVis 0
#define vis 1
vector<int> graph[105];
vector<int> graphT[105];
vector<int> order;
vector<int> scc[105];
int V,e,component=0;
int visited[105];
void dfsVisitOnGT(int source){
    visited[source] = vis;
    scc[component].push_back(source);
    for(int v : graphT[source]){
        if(not visited[v]){
            dfsVisitOnGT(v);
        }
    }
}
void SCC(){
    for(int i=0;i<V;i++){
        visited[i] = notVis;
    }
    for(int i=0;i<V;i++){
        int v = order[V-1-i];
        if(not visited[v]){
            dfsVisitOnGT(v);
            component++;
        }
    }
}
void dfsVisitOnG(int source){
    visited[source] = vis;
    for(int v : graph[source]){
        if(not visited[v]){
            dfsVisitOnG(v);
        }
    }
    order.push_back(source);
}
void dfsOnG(){
    for(int i=0;i<V;i++){
        visited[i] = notVis;
    }
    for(int i=0;i<V;i++){
        if(not visited[i]){
            dfsVisitOnG(i);
        }
    }
}
void printSCC(){
    cout<< "There are total " << component << " Strongly Connected Components found" << endl;
    for(int i=0;i<component;i++){
        cout<< "Component " << i+1 << " : ";
        for(int j=0;j<scc[i].size();j++){
            cout<< scc[i][j];
            j == scc[i].size()-1 ? cout<< endl : cout<< " ";
        }
    }
}
int main()
{
    cin>>V>>e;
    order.clear();
    for(int i=0;i<V;i++){
        graph[i].clear();
        graphT[i].clear();
        scc[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graphT[v].push_back(u);
    }
    dfsOnG();
    SCC();
    printSCC();
    order.clear();
    for(int i=0;i<V;i++){
        graph[i].clear();
        graphT[i].clear();
        scc[i].clear();
    }
    return 0;
}