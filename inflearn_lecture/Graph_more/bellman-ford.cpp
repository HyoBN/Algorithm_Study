#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist[101];

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main()
{
	vector<Edge> ed;
	int n,m,a,b,c,s,e;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		ed.push_back(Edge(a,b,c));
	}
	
	for(int i=1;i<=n;i++)
		dist[i]=2147000000;
	
	scanf("%d %d",&s,&e); // s : 출발node, e : 도착node
	dist[s]=0;
	
	for(int i=1;i<n;i++){ // i : 거치는 간선의 개수.
		for(int j=0;j<ed.size();j++){
			int u=ed[j].s;
			int v=ed[j].e;
			int w=ed[j].val;
			if(dist[s]!=2147000000 && dist[u]+w<dist[v]) //출발 node의 값과 가중치 값을 더한 값이 기존의 값보다 작다면.
				dist[v]=dist[u]+w; // 갱신!
		}
	}

	for(int j=0;j<ed.size();j++){ //음의 싸이클(가중치의 합이 0보다 작은 싸이클) 존재 여부 확인.
		int u=ed[j].s;
		int v=ed[j].e;
		int w=ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			printf("-1\n");
			exit(0);
		}

	}
	printf("%d",dist[e]);
	
}