#include <iostream>
#include <cstring>
using namespace std;

int t;
int arr[100001];
int first[100001];
int visited[100001];

int DFS(int start, int now, int cnt)
{
	if(visited[now])
	{
		if(first[now]!=start)
			return 0;
		return cnt-visited[now];
		
	}
	else
	{
		first[now]=start;
		visited[now]=cnt;
		return DFS(start, arr[now],cnt+1);
	}
}

int main()
{
	int n,answer;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		answer=0;
		memset(first, 0, sizeof(first));
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[j]);
		for(int j=1;j<=n;j++)
			if(!visited[j])
				answer+=DFS(j,j,1);
			
		
		printf("%d\n",n-answer);
	}
}