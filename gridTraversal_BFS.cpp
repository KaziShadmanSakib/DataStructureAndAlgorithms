/*Dummy of Grid Traversal using BFS*/
#include<bits/stdc++.h>
using namespace std;
int color[105][105], d[105][105];
char grid[105][105]; //"#" means obstacle
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m;
void bfs(int sx,int sy){
	queue<int> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			color[i][j] = 0; //white
			d[i][j] = 10000000;//infinite
		}
	}
	q.push(sx);
	q.push(sy);
	color[sx][sy] = 1; //gray
	d[sx][sy] = 0;
	while(not q.empty()){
		int ux = q.front();
		q.pop();
		int uy = q.front();
		q.pop();
		//explore all edges of u
		for(int i=0;i<4;i++){
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if(vx>=0 && vx<n && vy>=0 && vy<m && grid[vx][vy]!= '#' && color[vx][vy]==0){
				color[vx][vy] = 1;
				d[vx][vy] = d[ux][uy] + 1;
				q.push(vx);
				q.push(vy);  
			}
		}
	}	
}
int main()
{

	return 0;
}