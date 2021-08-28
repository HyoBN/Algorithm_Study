#include <iostream>
using namespace std;

int main()
{
	int n,m,cnt=0;
	int arr[10001];
	int i=0,j=0,sum;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sum=arr[0];
	
	while(i<=j && j<n)
	{
		if(sum<m)
			sum+=arr[++j];
		else if(sum==m){
			cnt++;
			sum+=arr[++j];
		}
		
		else if(sum>m){
			sum-=arr[i++];
			if(i>j){
				j=i;
				sum=arr[i];
			}
		}
	}
	printf("%d",cnt);
}