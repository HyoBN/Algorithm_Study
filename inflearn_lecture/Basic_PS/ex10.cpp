// 문제 10번. N개의 자연수를 입력받고 그 중 자릿수의 합이 최대가 되는 가장 큰 자연수 출력.
// ex. input  : 5
//				125 15232 79 1325 97
//     output : 97

#include <iostream>
#include <algorithm>
using namespace std;

int digit_sum(int x)
{
	int tmp,result=0;
	while(x>0)
	{
		tmp=x%10;
		result+=tmp;
		x/=10;
	}
	return result;
}


int main()
{
	int n,max_value=0;
	int res=0;
	int arr[101];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		if(max_value<=digit_sum(arr[i])){
			max_value=digit_sum(arr[i]);
			res=arr[i];
		}
				
	}
	
	printf("%d",res);
	
}