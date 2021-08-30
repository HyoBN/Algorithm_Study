#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool prime[4000001];

int main(void) {
	int n;
	int sum=0,cnt=0;
	int low=2,high=2;
	scanf("%d",&n);
	memset(prime,true,sizeof(prime));
		
	for (int i=2;i<=sqrt(n);i++)
		for (int j=i+i;j<=n;j+=i)
			prime[j] = false;
	while (true) {
		if(prime[high]==false){
			high++;
			continue;
		}
		else if(prime[low]==false)
		{
			low++;
			continue;
		}
		if (sum < n) {
			if (high > n) break;
			sum += high++;
			
		}
		else {
			if (sum==n) cnt++;
			sum -= low++;
		}
	}
	printf("%d",cnt);
	
}