// 문제 14번. N개의 자연수 입력, 각 자연수를 뒤집은 수가 소수이면 뒤집은 수를 출력.
//			뒤집었을 때 0은 출력되지 않도록.
// ex. input : 5 \n 32 55 62 3700 250
//     output : 23 73

#include <iostream>
#include <math.h>
using namespace std;


int reverse(int x)
{
	int res=0;
	while(x>0)
	{
		res*=10;
		res+=(x%10);
		x/=10;
	}
	return res;
}

bool isPrime(int x)
{
	if(x==1) return false;
	for(int i=2;i<=(int)sqrt(x);i++){
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	int arr[101];
	int re_arr[101];
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<n;i++)
		re_arr[i]=reverse(arr[i]);
	
	
	for(int i=0;i<n;i++)
		if(isPrime(re_arr[i]))
			printf("%d ",re_arr[i]);
}