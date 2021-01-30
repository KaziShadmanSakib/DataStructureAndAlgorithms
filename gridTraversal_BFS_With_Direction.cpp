#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,dir;
	node(){
		x = 0;
		y = 0;
		dir = 0;
	}
	node(int x,int y,int dir){
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};
int adjMatrix[105][105][4];
int d[105][105][4], color[105][105][4];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
void bfs(node source){
	queue<node> q;
	/*using for loop cause if there is not given any direction in the input*/
	/*checking all the directions*/
	for(int i=0;i<4;i++){
		source.dir = i;
		q.push(source);
		d[source.x][source.y][source.dir] = 0;
		color[source.x][source.y][source.dir] = 1;
	}
	while(not q.empty()){
		node u = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			node v;
			if(i==u.dir){
				v.x = u.x + dx[i];
				v.y = u.y + dy[i];
				v.dir = u.dir;
			}
			else{
				v.x = u.x;
				v.y = u.y;
				v.dir = i;
			}
			if(v.x>=0 && v.x<n && v.y>=0 && v.y<m && adjMatrix[v.x][v.y][v.dir]== '.' && color[v.x][v.y][v.dir]){
				q.push(v);
				d[v.x][v.y][v.dir] = d[u.x][u.y][u.dir] + 1;
				color[v.x][v.y][v.dir] = 1;
			}
		}
	}
}
int main()
{
	bfs(node(0,0,0));
	return 0;
}