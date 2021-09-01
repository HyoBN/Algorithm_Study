#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> q; // min-heap
	
	int n,m,a,b,c;
	int start,end;
	scanf("%d",&n);
	scanf("%d",&m);
	vector<pair<int,int>> graph[1001];
	vector<int> dist(n+1, 2147000000);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
	}
	
	scanf("%d %d",&start,&end);
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
	
	printf("%d",dist[end]);
	
}