#include <iostream>
#include <vector>
using namespace std;

int growth[1000001][3];

int main()
{
	int map[701][701];
	int m,n,x;
	scanf("%d %d",&m,&n);
	vector<int> total_growth(2*m-1);

	int k;
	int a,b,c;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		growth[i][0]=a;
		growth[i][1]=a+b;
		growth[i][2]=a+b+c;
		
	}
	
	for(int i=0;i<n;i++)
	{
		k=0;
		for(int j=0;j<3;j++)
		{
			for(;k<growth[i][j];k++)
				total_growth[k]+=j;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j==0)
				printf("%d ",total_growth[m-i-1]+1);
			else
				printf("%d ",total_growth[j+m-1]+1);
		}
		printf("\n");
	}
}