#include<bits/stdc++.h>
using namespace std;

struct node1{
    int v,w;
    node1(){
        this->v = 0;
        this->w = 0;
    }

    node1(int v, int w){
        this->v = v;
        this->w = w;
    }

    bool operator <(const node1 &a)const{
        return w>a.w || (w==a.w && v>a.v);
    }
};

struct node2{
    int u,v,w;
    node2(){
        this->u = 0;
        this->v = 0;
        this->w = 0;
    }
    node2(int u,int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

#define inf 1e5

int n,m;
vector<node1> adjList[10000];
vector<node2> edgeList;
int minCost[10000];
int previ[10000];

void dijkstra(int source){

    for(int i=0;i<n;i++){
        previ[i] = -1;
        minCost[i] = inf;
    }

    minCost[source] = 0;
    priority_queue<node1> pq;

    pq.push(node1(source,minCost[source]));

    while(not pq.empty()){

        int u = pq.top().v; pq.pop();

        for(int i=0;i<adjList[u].size();i++){
            int v = adjList[u][i].v;
            int w = adjList[u][i].w;

            if(minCost[v]>minCost[u] + w){
                minCost[v] = minCost[u] + w;
                previ[v] = u;
                pq.push(node1(v,minCost[v]));
            }

        }

    }


}

int minCost2[10000];
int previ2[10000];

bool bellmanford(int source){

    for(int i=0;i<n;i++){
        minCost2[i] = inf;
        previ2[i] = -1;
    }

    minCost2[source] = 0;

    for(int i=1;i<=n-1;i++){
        int flag = 0;
        for(int j=0;j<m;j++){
            int u = edgeList[j].u;
            int v = edgeList[j].v;
            int w = edgeList[j].w;
            if(minCost2[v] > minCost2[u] + w){
                minCost2[v] = minCost2[u] + w;
                previ2[v] = u;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    for(int i=0;i<m;i++){
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int w = edgeList[i].w;
        if(minCost2[v] > minCost2[u] + w){
            return true;
        }
    }
    return false;
}

void printPath(int source, int destination){

    if(destination==source){
        cout<< source << " ";
    }
    else if(previ[destination]==-1){
        cout<< "No path" << endl;
    }
    else{
        printPath(source, previ[destination]);
        cout<< destination << " ";
    }
}

void printPath2(int source, int destination){

    if(destination==source){
        cout<< source << " ";
    }
    else if(previ2[destination]==-1){
        cout<< "No path" << endl;
    }
    else{
        printPath(source, previ2[destination]);
        cout<< destination << " ";
    }
}

int main()
{

    cin>>n>>m;

    for(int i=0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(node1(v,w));
        edgeList.push_back(node2(u,v,w));
    }

    cout<< "Dijkstra" << endl;
    dijkstra(0);
    printPath(0,1);
    cout<<endl;
    cout<< "Bellmanford" << endl;
    if(bellmanford(0)){
        cout<< "Negative Cycle Found" << endl;
    }
    else{
        printPath2(0,1);
        cout<< endl;
    }
    return 0;
}