// 문제 65. 방향 그래프가 주어지면 1번 정점에서 n번 정점으로 가는 모든 경로의 가지 수 출력.

#include <iostream>
using namespace std;

int arr[21][21];
int visited[21]={0,1,};
int n,cnt=0;

void DFS(int v)
{
	if(v==n) cnt++;
	else{
		for(int i=1;i<=n;i++)
		{
			if(arr[v][i]==1 && visited[i]==0){
				visited[i]=1;
				DFS(i);
				visited[i]=0;
			}
		}
	}
}
int main()
{
	int m;
	int from, to;
	scanf("%d %d",&n, &m);
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&from, &to);
		arr[from][to]=1;
	}
	
	DFS(1);
	
	printf("%d",cnt);
}