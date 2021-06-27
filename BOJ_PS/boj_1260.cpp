#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int arr[1001][1001];
int visited[1001]={0,};
int n,m,v;

void dfs(int x)
{
	cout<<x<<" ";
	visited[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0 && arr[x][i]==1)
			dfs(i);
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x]=1;
	
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0 && arr[node][i]==1)
			{
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

int main()
{
	cin>>n>>m>>v;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[x][y]= arr[y][x]=1; //양방향이므로!
	}
	dfs(v);
	cout<<endl;
	
	memset(visited,0,sizeof(visited));
	bfs(v);
	

}