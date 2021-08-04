#include <iostream>
#include <cstring>
using namespace std;

int t,cnt;
int n,arr[1001];
int check[1001]={0,};

void D(int x)
{
	if(check[x]==1){
		cnt++;
		return;
	}
	
	else if(check[x]==0)
	{
		check[x]=1;
		D(arr[x]);
	}
}

int main()
{
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		memset(check,0,sizeof(check));
		cnt=0;
		scanf("%d",&n);
		
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[j]);
		
		for(int j=1;j<=n;j++)
			if(check[arr[j]]==0)
				D(arr[j]);
		
		printf("%d\n",cnt);
	}
}