//문제 67. 가중치 방향 그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을  출력하라.

#include <iostream>
using namespace std;

int n,cost=2147000000;
int arr[30][30];
int visited[30];

void DFS(int v, int sum)
{
	if(v==n)
	{
		if(sum<cost) cost=sum;
		return;
	}
	
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0 && arr[v][i]>0){
				visited[v]=1;
				DFS(i,sum+arr[v][i]);
				visited[v]=0;
			}

		}
	}
}

int main()
{
	int m,a,b,c;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		arr[a][b]=c;
	}
	
	visited[1]=1;
	DFS(1,0);
	printf("%d",cost);
}