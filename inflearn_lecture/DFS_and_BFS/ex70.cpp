// 문제 70. 그래프 최단 거리(BFS). 1번 정점에서 각 정점으로 가는 최소 이동 간선수 출력.
// input : 정점의 수 n과 간선의 수 m, 각 간선의 연결정보가 입력됨.
// output : 1번에서 각 정점까지의 최단 거리 출력.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> vec[21];
bool visited[21];
int answer[21];

int main()
{
	int n,m,a,b,x;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		vec[a].push_back(b);
	}
	visited[1]=true;
	q.push(1);;
	
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=0;i<vec[x].size();i++)
		{
			if(!visited[vec[x][i]])
			{
				visited[vec[x][i]]=true;
				q.push(vec[x][i]);
				answer[vec[x][i]]=answer[x]+1;
			}
		}
	}
	
	for(int i=2;i<=n;i++)
		printf("%d : %d\n",i,answer[i]);
	
}