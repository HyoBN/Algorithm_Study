#include <iostream>
#include <cmath>
using namespace std;

int prime[1000001];

int main(void) {
	int m, n;
	scanf("%d %d",&m,&n);
	for (int i=m; i<=n; i++)
		prime[i] = true;
	
	prime[1] = false;
	
	for (int i = 2; i <= sqrt(n); i++)
		for (int j =i+i; j<=n; j+=i)
			prime[j] = false;
	
	for (int i = m; i <= n; i++)
		if (prime[i])
			printf("%d\n", i);
}