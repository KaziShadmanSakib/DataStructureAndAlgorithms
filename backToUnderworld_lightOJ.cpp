#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 1
#define inf INT_MAX
vector<int> adjList[1000005];
int color[1000005];
int bfs(int s){
	int blck = 0, gry = 0;
	color[s] = gray;
	queue<int> q;
	q.push(s);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adjList[u]){
			if(color[v]==white){
				q.push(v);
				if(color[u]==black){
					color[v] = gray;
					gry++;
				}
				else{
					color[v] = black;
					blck++;
				}
			}
		}
	}
	return max(blck,gry);
}
int main()
{
	int testCase, i=0;
	cin>>testCase;
	while(testCase--){
		int vertex;
		int e;
		cin>>e;
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			if(u>v){
				vertex = u;
			}
			else{
				vertex = v;
			}
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		memset(color,white,sizeof(color));
		int res = bfs(1);
		cout<< "Case " << ++i << ": " << res <<endl;
	}
	return 0;
}