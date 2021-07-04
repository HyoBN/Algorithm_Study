#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool prime[1000001];
int num;
int gold;

int main(void) {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= sqrt(1000000); i++)
		for (int j =i+i; j<=1000000; j+=i)
			prime[j] = false;
	
	while(true)
	{
		gold=0;
		scanf("%d",&num);
		if(num==0)
			break;
		for(int i=num;i>1;i--)
		{
			if(prime[i]==true && prime[num-i]==true)
			{
				printf("%d = %d + %d\n",num,num-i,i);
				gold=1;
				break;
			}
	
		}
		if(gold==0)
			printf("Goldbach's conjecture is wrong.\n");
	}
	
	
	
	
	
	
}