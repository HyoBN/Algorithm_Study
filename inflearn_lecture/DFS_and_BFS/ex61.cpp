// 문제 61. n개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 +, - 연산을 사용하여 특정 수 m을 만드는 경우가 몇 가지 있는지 출력하라. 각 원소는 연산에 한 버만 사용된다.
// ex. input : 4 12 \n 2 4 6 8
//     output : 4


#include <iostream>
using namespace std;

int n,m;
int arr[11];
int cnt=0;
void DFS(int l, int x)
{
	if(l==n){
		if(x==m)
			cnt++;	
	}
	else
	{
		DFS(l+1,x+arr[l]);
		DFS(l+1,x-arr[l]);
		DFS(l+1,x);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	DFS(0,0);
	if(cnt==0) printf("-1");
	else printf("%d",cnt);
}