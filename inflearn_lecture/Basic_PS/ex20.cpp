// 문제 20. A,B 두 사람이 가위바위보를 N번 하여 A가 이기면 A, B가 이기면 B, 비기면 D를 출력.
// 			가위 : 1, 바위 : 2, 보 : 3 으로 입력받음.
// ex. input : 5 \n 2 3 3 1 3 \n 1 1 2 2 3
//	   output : A \n B \n A \n B \n D


#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[101];
	int b[101];
	
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	
	for(int i=0;i<n;i++)
	{
		if(b[i]-a[i]==1 || b[i]-a[i]==-2)
			printf("B\n");
		else if(a[i]==b[i])
			printf("D\n");
		else
			printf("A\n");
	}
}