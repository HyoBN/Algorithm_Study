#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int vex;
	int dis;
	Edge(int a, int b){
		vex=a;
		dis=b;
	}
	bool operator<(const Edge &b)const{
		return dis>b.dis;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int,int>> graph[20001];
	int n,m,a,b,c;
	int start;
	scanf("%d %d",&n,&m);
	scanf("%d",&start);
	vector<int> dist(n+1, 2147000000);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
	}
	q.push(Edge(start,0));
	dist[start]=0;
	
	while(!q.empty())
	{
		int now=q.top().vex; 
		int cost=q.top().dis;
		q.pop();
		if(cost>dist[now]) continue;
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
	
	for(int i=1;i<=n;i++)
	{
		if(dist[i]!=2147000000) printf("%d\n",dist[i]);
		else printf("INF\n");
	}
	
}