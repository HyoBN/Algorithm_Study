#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unf[100001];

struct Edge{
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c){ //생성자
		v1=a;
		v2=b;
		cost=c;
	}
	
	bool operator<(Edge &b){ //연산자 오버로딩
		return cost<b.cost;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main()
{
	vector<Edge> e;
	int n,m,a,b,c,res=0,cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		unf[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		e.push_back(Edge(a,b,c));
	}
	sort(e.begin(),e.end());
	
	for(int i=0;i<m;i++)
	{
		int fa=Find(e[i].v1);
		int fb=Find(e[i].v2);
		if(fa!=fb)
		{
			res+=e[i].cost;
			Union(e[i].v1, e[i].v2);
			cnt++;
			if(cnt==n-2) break;
		}
	}
	printf("%d",res);
}