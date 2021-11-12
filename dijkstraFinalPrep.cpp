#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

struct node{
    int v,w;

    node(){
        this->v = 0;
        this->w = 0;
    }
    node(int v,int w){
        this->v = v;
        this->w = w;
    }

    bool operator <(const node &a)const{

        return w>a.w || (w==a.w && v>a.v);


    }
};


int n,m;
vector<node> adjlist[1000];
int minCost[10000];
int previ[10000];

void dijkstra(int source){

    for(int i=0;i<n;i++){
        minCost[i] = inf;
        previ[i] = -1;
    }

    minCost[source] = 0;

    priority_queue<node> pq;
    pq.push(node(source, minCost[source]));

    while(not pq.empty()){

        int u = pq.top().v; pq.pop();

        for(int i=0;i<adjlist[u].size();i++){

            int v = adjlist[u][i].v;
            int w = adjlist[u][i].w;

            if(minCost[v] > minCost[u] + w){

                minCost[v] = minCost[u] + w;

                previ[v] = u;

                pq.push(node(v,minCost[v]));

            }

        }


    }

}

vector<int> ans;
void printPath(int source,int destination){

    if(destination == source){

        ans.push_back(source);
    }

    else if(previ[destination] == -1){

        cout<< "Not Reachable";
    }

    else{

        printPath(source, previ[destination]);

        ans.push_back(destination);

    }
}

int main()
{

    cin>>n >>m;

    for(int i=0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adjlist[u].push_back(node(v,w));
        adjlist[v].push_back(node(u,w));
    }

    dijkstra(0);
    printPath(0,1);

    for(int i=0;i<ans.size();i++){

        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}