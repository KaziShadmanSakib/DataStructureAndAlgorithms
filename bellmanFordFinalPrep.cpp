#include<bits/stdc++.h>
using namespace std;

#define inf 1e5

struct node{
    int u,v,w;

    node(){
        this->u = 0;
        this->v = 0;
        this->w = 0;
    }

    node(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;   
    }

};

int n,m;
vector<node> graph;
int minCost[10000];
int previ[10000];

bool bellmanFord(int source){

    for(int i=0;i<n;i++){
        minCost[i] = inf;
        previ[i] = -1;
    }

    minCost[source] = 0;

    for(int i=1;i<=n-1;i++){
        int flag = 0;
        for(int j=0;j<m;j++){
            int u = graph[j].u;
            int v = graph[j].v;
            int w = graph[j].w;
            if(minCost[v]> minCost[u] + w){
                minCost[v] = minCost[u] + w;
                previ[v] = u;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

    for(int i=0;i<m;i++){
        int u = graph[i].u;
        int v = graph[i].v;
        int w = graph[i].w;
        if(minCost[v]>minCost[u]+w){
            return true;
        }
    }
    return false;
}

int main()

{

    cin>>n>>m;
    for(int i=0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(node(u,v,w));
    }

    if(bellmanFord(0)){

        cout<< "Negative Cycle Found!!" << endl;
    }

    else{
        cout<< "No Negative Cycle Found!!" << endl;
    }

    return 0;
}