#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define inf INT_MAX
string adjMatrix[105][105];
string RGB[105];
int d[105][105];
int color[105][105];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int v,e;
void bfs(int sx,int sy){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	color[sx][sy] = gray;
	d[sx][sy] = 0;
	while(not q.empty()){
		int ux = q.front();
		q.pop();
		int uy = q.front();
		q.pop(); 
		for(int i=0;i<4;i++){
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if(vx>=0 && vx<v && vy>=0 && vy<e && color[vx][vy]==white && adjMatrix[vx][vy] != adjMatrix[ux][uy]){
				color[vx][vy] = gray;
				d[vx][vy] = d[ux][uy] + 1;
				q.push(vx);
				q.push(vy);
			}
		}
		color[ux][uy] = black;
	}
}
int main()
{
	cin>>v>>e;
	for(int i=0;i<v;i++){
		cin>>RGB[i];
		for(int j=0;j<e;j++){
			adjMatrix[i][j] = RGB[i][j];
		}
	}
	memset(color,white,sizeof(color));
	memset(d,inf,sizeof(d));
	bfs(0,0);
	cout<<"Shortest path length = "<< d[v-1][e-1]<<endl;
	return 0;
}