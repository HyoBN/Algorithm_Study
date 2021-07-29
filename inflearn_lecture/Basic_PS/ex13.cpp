// 문제 13번. N자리 자연수가 입력되면 그 자연수에서 가장 많이 사용된 숫자를 출력.
// ex. input : 1230565625
//	   output : 5

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c[101];
	int max=0,ans;
	int arr[10]={0,};
	scanf("%s",&c);
	
	for(int i=0;c[i]!='\0';i++)
		arr[c[i]-48]++;
	
	for(int i=0;i<10;i++)
	{
		if(arr[i]>=max){
			max=arr[i];
			ans=i;
		}
	}
	printf("%d",ans);
}