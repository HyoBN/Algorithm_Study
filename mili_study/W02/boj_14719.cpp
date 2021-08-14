#include <iostream>
using namespace std;

int main()
{
	int h,w,cnt=0;
	int height[501];
	int world[501][501];
	int start_index, end_index;
	scanf("%d %d",&h,&w);
	
	for(int i=0;i<w;i++)
		scanf("%d",&height[i]);
	
	for(int i=0;i<w;i++)
	
		for(int j=h-1;j>=h-height[i];j--)
			world[i][j]=1;
	
	for(int i=0;i<h;i++)
	{
		start_index=-1;
		end_index=-1;
		
		for(int j=0;j<w;j++)
		{
			if(world[j][i]==1 && start_index==-1)
				start_index=j;
			
			else if(world[j][i]==1 && start_index!=-1)
			{
				end_index=j;
				cnt+=end_index-start_index-1;
				start_index=j;
				end_index=-1;
			}
				
		}
		
	}
	printf("%d",cnt);	
}