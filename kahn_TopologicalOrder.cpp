#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[105];
vector<int> order;
int V,e,cnt=0;
queue<int> q;
int indegree[105];
void kahn(){
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(not q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v : adjList[u]){
            indegree[v] = indegree[v] - 1;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        cnt++;
    }
    if(cnt!=V){
        cout<< "There exists a cycle in the graph" << endl;
        return;
    }
}
void topologicalOrder(){
    cout<< "Topological Order:" << endl; 
    for(int i=0;i<order.size();i++){
        cout<< order[i];
        i == order.size()-1 ? cout<< endl : cout<< " ";
    }
}
int main()
{
    cin>>V>>e;
    order.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
        indegree[i] = 0;
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        indegree[v]++;
    }
    kahn();
    topologicalOrder();
    order.clear();
    for(int i=0;i<V;i++){
        adjList[i].clear();
    }
    return 0;
}