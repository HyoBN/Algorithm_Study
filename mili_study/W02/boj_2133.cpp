#include <iostream>
using namespace std;

int main() {
    int n;
	int dp[30]={0,3,11,}; //2,4,6,... 짝수만 저장.
    scanf("%d",&n);
    if(n%2==1)
		printf("0");
	else
	{
		for(int i=3; i<=n/2; i++) {
			dp[i] = dp[1] * dp[i-1] + 2;
			for(int j=i-2; j>0; j--)
				dp[i]+=2*dp[j];
		}
		printf("%d",dp[n/2]);
	}
    
}