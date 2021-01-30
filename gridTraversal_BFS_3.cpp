#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define inf INT_MAX
struct node{
	int x;
	int y;
	node(){
		x = 0;
		y = 0;
	}
	node(int x,int y){
		this->x = x;
		this->y = y;
	}
};
string adjMatrix[105];
string RGB[105];
int color[105][105];
int previ[105][105][2];
int d[105][105];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void bfs(node source){
	queue<node> q;
	color[source.x][source.y] = gray;
	d[source.x][source.y] = 0;
	q.push(source);
	while(not q.empty()){
		node u = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			node v;
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			if(v.x>=0 && v.x<n && v.y>=0 && v.y<m && color[v.x][v.y]==white && adjMatrix[v.x][v.y]!=adjMatrix[u.x][u.y]){
				color[v.x][v.y] = gray;
				d[v.x][v.y] = d[u.x][u.y] + 1;
				previ[v.x][v.y][0] = u.x;
				previ[v.x][v.y][1] = u.y;
				q.push(v);
			}
		}
		color[u.x][u.y] = black;
	}
}
void printPath(int rsx,int rsy,int dx,int dy){
	if(rsx == 0 && rsy ==0){
		cout<< "(" << rsx << "," << rsy << ")" << "-> ";
	}
	else if(previ[dx][dy][0]==-1 && previ[dx][dy][1]==-1){
		cout<< "There is no path" << endl;
	}
	else{
		printPath(previ[rsx][rsy][0],previ[rsx][rsy][1],dx,dy);
		cout<< "(" << rsx << "," << rsy << ")";
		if(rsx == dx && rsy == dy){
			cout<<endl;
		} 
		else{
			cout<< "-> ";
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>RGB[i];
		for(int j=0;j<m;j++){
			adjMatrix[i][j] = RGB[i][j];
		}
	}
	memset(color,white,sizeof(color));
	memset(d,inf,sizeof(d));
	memset(previ,-1,sizeof(previ));
	bfs(node(0,0));
	cout<< "Shortest path length = " << d[n-1][m-1] <<endl;
	printPath(n-1,m-1,n-1,m-1);
	return 0;
}