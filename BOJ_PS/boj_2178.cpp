#include <iostream>
#include <queue>
using namespace std;

int n, m;
int check[101][101];
int visited[101][101];
int map[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y) 
{
	visited[x][y] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); 
		for (int i=0;i<4;i++) 
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (0<=nx &&nx<n && 0<=ny && ny<m)
			{
				if (map[nx][ny] == 1 && visited[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}

			}

		}
	}

}

int main(void) 
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&map[i][j]);

	BFS(0,0);
	printf("%d",check[n-1][m-1]+1);

}