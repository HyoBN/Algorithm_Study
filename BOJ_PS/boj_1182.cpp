#include <iostream>
using namespace std;

int n,s,arr[21];
int cnt=0;
bool visited[21];

void DFS(int x)
{
	if(x==n) 
	{
		int sum=0;
		bool empty_set=true;
		for(int i=0;i<n;i++)
			if(visited[i]==true)
			{
				empty_set=false;
				sum+=arr[i];
			}
		if(sum==s && !empty_set)
			cnt++;
		
	}
	else{
		visited[x]=true;
		DFS(x+1);
		visited[x]=false;
		DFS(x+1);
	}
}

int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	DFS(0);
	printf("%d",cnt);
}