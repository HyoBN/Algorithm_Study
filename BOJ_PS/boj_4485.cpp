#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,pair<int,int>> d_pair;
int map[126][126];
int dist[126][126];
bool visited[126][126];

pair<int,int> dir[4]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
	int loop=1;
	
	while(true){
		int n;
		scanf("%d",&n);
		if(n==0) break;

		for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dist[i][j]=2147000000;
		
		memset(visited,false,sizeof(visited));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&map[i][j]);
		
		priority_queue<d_pair,vector<d_pair>,greater<d_pair>> q;

		q.push({ 0, {0, 0} });
		visited[0][0]=true;
		
		while(!q.empty())
		{

			int y = q.top().second.first;
			int x = q.top().second.second;
			int cost=q.top().first;
			q.pop();

			for(int i=0;i<4;i++)
			{
				int ny=y+dir[i].first;
				int nx=x+dir[i].second;
				int ncost=cost+map[ny][nx];

				if(!visited[ny][nx] && dist[ny][nx]>ncost
				   && ny>=0 && nx>=0 && ny<n && nx<n)
				{
					visited[ny][nx]=true;
					dist[ny][nx]=ncost;
					q.push({ncost,{ny,nx}});
				}
			}
		}
		printf("Problem %d: %d\n",loop++,map[0][0]+dist[n-1][n-1]);
		
		
	}
	
}