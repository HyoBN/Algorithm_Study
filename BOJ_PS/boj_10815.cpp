#include <iostream>
#include <cstring>
using namespace std;

const int s=10000000;
bool check[20000003];
int main()
{
	int n,m,x;
	memset(check,false,sizeof(check));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		check[x+s]=true;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		printf((check[x+s]==true) ? "1 " : "0 ");
	}
}