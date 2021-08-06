// 문제 65. 자연수 n와 n x n 격자 미로가 주어지면 미로를 탈출하는 경우의 수를 출력.

#include <iostream>
using namespace std;

int n,cnt=0;
int map[21][21];
int visited[21][21];
int x_arr[4]={1,0,-1,0};
int y_arr[4]={0,-1,0,1};

void DFS(int y, int x)
{
	int nx,ny;
	if(y==n && x==n) cnt++;
	
	else{
		for(int i=0;i<4;i++)
		{
			ny=y+y_arr[i];
			nx=x+x_arr[i];
			if(nx<1 || ny<1 || nx>n || ny>n) continue;
			if(map[ny][nx]==0 && visited[ny][nx]==0){
				visited[ny][nx]=1;
				DFS(ny,nx);
				visited[ny][nx]=0;
			}

		}
	}
	
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	visited[1][1]=1;
	DFS(1,1);
	printf("%d",cnt);
	
}