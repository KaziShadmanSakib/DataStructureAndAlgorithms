#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int n,m;
char matrix[100][100];
int vis[100][100];
int dis[100][100];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int sourcex, int sourcey, int disx, int disy){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j] = 0;
            dis[i][j] = inf;
        }
    }

    queue<int> q;

    dis[sourcex][sourcey] = 0;
    vis[sourcex][sourcey] = 1;

    q.push(sourcex);
    q.push(sourcey);

    while(not q.empty()){

        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();

        for(int i=0;i<4;i++){

            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m){
                if(matrix[ux][uy]!= matrix[vx][vy] && not vis[vx][vy]){

                    q.push(vx);
                    q.push(vy);

                    dis[vx][vy] = dis[ux][uy] + 1;
                    vis[vx][vy] = 1;
                }

            }

        }

    }

}

int main()
{

    cin>> n >>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char color;
            cin>> color;
            matrix[i][j] = color;
        }
    }

    bfs(0,0,n-1,m-1);

    cout<< dis[n-1][m-1] << endl;

    return 0;
}