// 문제 25. Jolly jumpers.
// n개의 정수로 이루어진 수열에서 서로 인접해 있는 두 수의 차가 1에서 n-1의 값을 모두 가지면 YES를 출력, 아니면 NO를 출력하라.
// ex. input : 5 \n 1 4 2 3 7
// output : YES

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	bool flag=false;
	int arr[101];
	int check[101];
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(int i=1;i<n;i++)
		check[i]=abs(arr[i]-arr[i-1]);
	
	sort(check+1,check+n);
	
	for(int i=1;i<n;i++)
		if(check[i]!=i) flag=true;
	
	if(flag) printf("NO");
	else printf("YES");
}