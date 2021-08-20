#include <iostream>
#include <algorithm>
using namespace std;

int n,q;
int map[5001][5001];
int usado[5001][5001];

void DFS(int now, int start, int end, int min_value)
{
	if(map[now][end]!=0){
		usado[start][end]=min(min_value,map[now][end]);
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(map[now][i]!=0){
			if(min_value==0)
				DFS(i,start,end,map[now][i]);
			else
				DFS(i,start,end,(int)min(min_value,map[now][i]));
		}
	}
}

int main()
{
	int a,b,c;
	int k,v;
	int cnt;
	
	scanf("%d %d",&n,&q);
	
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		map[a][b]=c;
		map[b][a]=c;
		usado[a][b]=c;
	}

	int tmp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j || usado[i][j]!=0) continue;
			DFS(i,i,j,1000000001);

		}
	}
	
	for(int i=0;i<q;i++)
	{
		cnt=0;
		scanf("%d %d",&k,&v);
		
		for(int i=1;i<=n;i++)
			if(usado[v][i]>=k || usado[i][v]>=k)
				cnt++;
		printf("%d\n",cnt);
	}
	
}