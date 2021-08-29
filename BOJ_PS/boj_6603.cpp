#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int arr[13];
	bool tmp[13]={0,0,0,0,0,0,1,1,1,1,1,1,1};
	
	while(true){
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		do{
			for(int i=0;i<n;i++)
				if(tmp[i]==0 & arr[i]!=0)
					printf("%d ",arr[i]);
			printf("\n");
		}while(next_permutation(tmp,tmp+n));
		printf("\n");
	}
}