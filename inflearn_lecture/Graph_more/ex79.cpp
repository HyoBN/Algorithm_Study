//문제 78. MST - Prim 알고리즘 : priority_queue 활용.
// 도시의 개수 V와 도로의 개수 E 입력, E개만큼의 a,b,c 입력(a도시에서 b도시로 c만큼의 유지비용으로 연결됨)
// 모든 도시를 연결하는데 필요한 최소비용 출력.


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ch[30];

struct Edge{
	int e;
	int val;
	Edge(int a, int b)
	{
		e=a;
		val=b;
	}
	bool operator<(const Edge &b)const{ //부등호 방향에 따라 최대힙, 최소힙 결정 가능.
		return val>b.val;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int, int>> map[30];
	int n,m,a,b,c,res=0;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c)); //무방향 그래프.
	}
	
	q.push(Edge(1,0));
	
	while(!q.empty())
	{
		Edge tmp = q.top();
		q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		
		if(ch[v]==0) //노드 방문 여부.
		{
			res+=cost;
			ch[v]=1;
			for(int i=0;i<map[v].size();i++)
				q.push(Edge(map[v][i].first, map[v][i].second));
		}
	}
	
	printf("%d",res);
}