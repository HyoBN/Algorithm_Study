#include <iostream>
using namespace std;

int arr[1001][1001];
int visited[1001]={0,};
int n,m;
int u,v;

void dfs(int x)
{
	visited[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0 && arr[x][i]==1)
			dfs(i);
	}
}

int main()
{
	int count=0;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		arr[u][v]= arr[v][u]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			count++;
		}
	}
	cout<<count;	
		
}