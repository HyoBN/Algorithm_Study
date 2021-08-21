#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int vex;
	int dis;
	Edge(int a, int b){
		vex=a;
		dis=b;
	}
	bool operator<(const Edge &b)const{ //min-heap
		return dis>b.dis;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int,int>> graph[30];
	int n,m,a,b,c;
	scanf("%d %d",&n,&m);
	vector<int> dist(n+1, 2147000000);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
	}
	q.push(Edge(1,0));
	dist[1]=0;
	
	while(!q.empty())
	{
		int now=q.top().vex; //min-heap이므로 가장 작은 값이 항상 top에 저장됨.
		int cost=q.top().dis;
		q.pop();
		if(cost>dist[now]) continue; //시간 단축.
		for(int i=0;i<graph[now].size();i++)
		{
			int next=graph[now][i].first;
			int nextDis=cost+graph[now][i].second;
			if(dist[next]>nextDis){
				dist[next]=nextDis;
				q.push(Edge(next, nextDis));
			}
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		if(dist[i]!=2147000000) printf("%d : %d\n",i,dist[i]);
		else printf("%d : impossible\n",i);
	}
	
}