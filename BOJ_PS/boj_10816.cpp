#include <iostream>
#include <cstring>
using namespace std;

const int s=10000000;
int check[20000003];
int main()
{
	int n,m,x;
	memset(check,0,sizeof(check));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		check[x+s]++;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		printf("%d ",check[x+s]);
	}
}