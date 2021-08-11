#include <iostream>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
int w,h,cnt,nx,ny;
int y_arr[]={1,1,0,-1,-1,-1,0,1};
int x_arr[]={0,1,1,1,0,-1,-1,-1};

void DFS(int y, int x)
{
	visited[y][x]=true;
	for(int i=0;i<8;i++)
	{
		ny=y+y_arr[i];
		nx=x+x_arr[i];
		if(ny>=0 && ny<h && nx>=0 && nx<w && visited[ny][nx]==false && map[ny][nx]==1)
			DFS(ny,nx);
			
	}
}

int main()
{
	while(true)
	{
		scanf("%d %d",&w,&h);
		if(w==0 && h==0) break;
		
		memset(map,0,sizeof(map));
		memset(visited,false,sizeof(visited));
		cnt=0;
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&map[i][j]);
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				if(visited[i][j]==false && map[i][j]==1){
					cnt++;
					DFS(i,j);
				}
			}
		printf("%d\n",cnt);
		
	}
	
}