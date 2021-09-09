#include <iostream>
using namespace std;

const int INF = 2147000000;

struct edge{
	int a,b,c;
};

int n,m;
long long dist[501];
edge city[6001];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){
		edge tmp;
		scanf("%d %d %d",&tmp.a, &tmp.b, &tmp.c);
		city[i]=tmp;
	}
	
	for(int i=0;i<501;i++)
		dist[i]=INF;
	
	dist[1]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			int a=city[j].a;
			int b=city[j].b;
			int c=city[j].c;
			if(dist[a]==INF || dist[b]<=dist[a]+c)
				continue;
			
			dist[b]=dist[a]+c;
			if(i==n){
				printf("-1");
				return 0;
			}
			
		}
	}
	
	for(int i=2;i<=n;i++){
		if(dist[i]==INF)
			printf("-1\n");
		else
			printf("%lld\n",dist[i]);
	}
}
