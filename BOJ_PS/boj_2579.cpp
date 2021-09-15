#include <iostream>
using namespace std;

int main()
{
	int arr[301];
	int dp[301];
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	dp[3]=max(arr[1],arr[2])+arr[3];
	for(int i=4;i<=n;i++){
		dp[i]=max(dp[i-2],dp[i-3]+arr[i-1])+arr[i];
	}
	printf("%d",dp[n]);
}