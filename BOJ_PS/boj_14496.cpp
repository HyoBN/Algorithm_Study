#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 2147000000;
int main()
{
	priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> q; // min-heap
	
	int n,m,a,b;
	int start,end;
	scanf("%d %d",&start,&end);
	scanf("%d %d",&n,&m);
	
	vector<pair<int,int>> graph[1001];
	vector<int> dist(n+1, INF);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a].push_back(make_pair(b,1));
		graph[b].push_back(make_pair(a,1));
	}

	q.push({start,0});
	dist[start]=0;
	
	while(!q.empty())
	{
		int now=q.top().first; 
		int cost=q.top().second;
		q.pop();
		if(cost>dist[now]) continue; //시간 단축.
		for(int i=0;i<graph[now].size();i++)
		{
			int next=graph[now][i].first;
			int nextDis=cost+graph[now][i].second;
			if(dist[next]>nextDis){
				dist[next]=nextDis;
				q.push({next, nextDis});
			}
		}
	}
	printf("%d",dist[end] == INF ? -1 : dist[end]);
}