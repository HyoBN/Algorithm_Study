// 문제 77. Disjoint=set : Union&Find
// 학생수 n, 학생간 친구여부 숫자쌍 개수 m을 입력받고, m줄에 걸쳐 친구인 학생 두 명이 숫자쌍으로 주어진다.
// 마지막 줄에는 두 학생이 친구인지 확인하는 숫자쌍이 주어진다. 친구면 YES, 아니면 NO를 출력.

#include <iostream>
using namespace std;

int unf[1001];

int Find(int v)
{
	if(v==unf[v]) return v;
	else return unf[v] = Find(unf[v]); // 경로 압축. 완전 비대칭 트리 방지.
}

void Union(int a, int b)
{
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main()
{
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		unf[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		Union(a,b);
	}
	
	scanf("%d %d",&a,&b);
	a=Find(a);
	b=Find(b);
	if(a==b) printf("YES");
	else printf("NO"); 
}