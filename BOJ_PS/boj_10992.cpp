#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		    printf(" ");
		    
		if(i==0)
		{
		    printf("*\n");
		    continue;
		}
		
		if(n<2) break;
		
		printf("*");
		for(int k=0;k<2*(i-1)+1;k++)
		    printf(" "); 
		printf("*");
		printf("\n");
	}
	
	
	for(int x=0;x<2*n-1;x++)
	    printf("*");
	
}