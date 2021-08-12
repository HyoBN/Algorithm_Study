#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int m,n;
	int res=0;
	int map[1001][1001];
	int y_arr[]={1,0,-1,0};
	int x_arr[]={0,1,0,-1};
	int nx,ny;
	
	queue<pair<int, int>> q;
	pair<int, int> tmp;
	
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==1)
				q.push(make_pair(i,j));
		}
	}
	
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();	
		for(int i=0;i<4;i++)
		{
			ny=tmp.first+y_arr[i];
			nx=tmp.second+x_arr[i];
			
			if(nx>=0 && ny>=0 && nx<m && ny<n && map[ny][nx]==0)
			{
				map[ny][nx]=map[tmp.first][tmp.second]+1;
				q.push(make_pair(ny,nx));
			}
		}
		
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0)
			{
				printf("-1");
				return 0;
			}
			else if(res<map[i][j])
				res=map[i][j];
		}
	}
	printf("%d",res-1);
	
}