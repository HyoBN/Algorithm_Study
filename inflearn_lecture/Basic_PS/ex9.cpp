// 문제 9번. 모두의 약수 : 1부터 N까지 각 숫자들의 약수의 개수를 출력.
// ex. input : 8
//	   output : 1 2 2 3 2 4 2 4

#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int arr[50001]={0,};
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			arr[j]++;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);

}