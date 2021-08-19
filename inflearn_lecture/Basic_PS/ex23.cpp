//문제 23번. n개의 숫자 중 연속적으로 같거나 증가하는 부분의 최대 길이를 출력하시오.
// ex. input : 9 \n 5 7 3 3 12 12 13 10 11
// output : 5
#include <iostream>
using namespace std;

int main()
{
	int n;
	int arr[100001];
	int cnt,max=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=arr[i-1]) cnt++;
		else
		{
			if(max<cnt) max=cnt;
			cnt=1;
		}
	}
	printf("%d",max);
}