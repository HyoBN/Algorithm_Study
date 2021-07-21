#include <iostream>
using namespace std;

int main()
{
	int arr[2][100001]={0,};
	int dp[2][100001]={0,};
	int t,n;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<2;j++)
			for(int k=0;k<n;k++)
				cin>>arr[j][k];
		
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0];
		dp[1][1] = arr[1][1] + dp[0][0];
		
		for(int k=2;k<n;k++)
		{
			dp[0][k]=arr[0][k] + max(dp[1][k-1],dp[1][k-2]);
			dp[1][k]=arr[1][k] + max(dp[0][k-1],dp[0][k-2]);	
		}
		
		cout<<max(dp[0][n-1], dp[1][n-1])<<endl;
	}
}