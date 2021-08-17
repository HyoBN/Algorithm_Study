#include <iostream>
using namespace std;

int main()
{
		
	int n,m;
	int arr[1000001];
	int maxi=0;
	long long sum=0;
	long long low=0,mid,high=0,ans=0;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(maxi<arr[i]) maxi=arr[i];
	}
	
	high=maxi;
	while(low<=high)
	{
		mid=(low+high)/2;
		sum=0;
		for(int i=0;i<n;i++)
			if(mid<arr[i])
				sum+=arr[i]-mid;
		
		if(sum>=m){
			if(ans<mid) ans=mid;
			low=mid+1;
		}
			
		else			
			high=mid-1;	
		
		
	}
	printf("%lld",ans);
}