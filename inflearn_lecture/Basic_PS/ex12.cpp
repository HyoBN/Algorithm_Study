//문제 12번. 1부터 자연수 N까지 자연수를 적을 때 총 몇개의 숫자(0~9)가 쓰여지는가
// ex. input : 15
//	   output : 21 
// 1 2 3 4 5 6 7 8 9 1
// 0 1 1 1 2 1 3 1 4 1
// 5
// 21개.

#include <iostream>

using namespace std;

int main()
{
	int n, sum=0,digit=1,tmp=9,ans=0;
	scanf("%d",&n);
	
	while(sum+tmp<n)
	{
		ans+=(digit*tmp);
		sum+=tmp;
		digit++;
		tmp*=10;
	}
	
	ans+=((n-sum)*digit);
	printf("%d",ans);
	
	
}