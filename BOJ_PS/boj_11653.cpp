#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool prime[10000001];


int main()
{
	int n;
	
	cin>>n;
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++)
		for (int j =i+i; j<=n; j+=i)
			prime[j] = false;
	
	while(true)
	{
		if(n==1) break;
		for(int i=2;i<=n;i++)
		{
			if(prime[i]==true && n%i==0)
			{
				cout<<i<<endl;
				n/=i;
				break;
			}
		}
		
	}
}