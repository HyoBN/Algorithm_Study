#include <iostream>
using namespace std;

int map[65][65];

void quad(int y,int x,int size)
{
	bool flag=false;
	if(size==1) 
	{
		printf("%d",map[y][x]);
		return;
	}
	
	for(int i=y;i<y+size;i++)
	{
		for(int j=x;j<x+size;j++)
		{
			if(map[i][j]!=map[y][x])
				flag=true;
			
		}
		
	}
	if(flag){
		printf("(");
		quad(y,x,size/2);
		quad(y,x+size/2,size/2);
		quad(y+size/2,x,size/2);
		quad(y+size/2,x+size/2,size/2);
		printf(")");
	}
	else
		printf("%d",map[y][x]);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&map[i][j]);
	
	quad(1,1,n);
}
