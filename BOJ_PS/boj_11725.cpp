#include <iostream>
#include <vector>
using namespace std;

bool visited[100001];
vector<int> v[100001];
int parents[100001];

void DFS(int idx)
{
	visited[idx]=true;
	for(int i=0;i<v[idx].size();i++)
	{
		if(!visited[v[idx][i]]){
			parents[v[idx][i]]=idx;
			DFS(v[idx][i]);
		}
	}
	return;
	
}

int main()
{
	int n,a,b;
	scanf("%d",&n);
	
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			DFS(i);
	}
	for(int i=2;i<=n;i++)
		printf("%d\n",parents[i]);
}