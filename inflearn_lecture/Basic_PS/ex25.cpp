// 문제 25. N명의 학생의 점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력. 동점은 동일 석차로 처리.
// ex. input : 5 \n 90 85 92 95 90
// output : 3 5 2 1 3

#include <iostream>
using namespace std;

int main()
{
	int a[200];
	int b[200];
	int n;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[j]>a[i]) b[i]++;

	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
}