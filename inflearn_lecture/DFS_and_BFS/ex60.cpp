// 문제 60번. n개의 원소가 있는 자연수 집합을 두 개의 부분 집합으로 나누었을 떄, 두 부분집합의 합이 서로 같은 경우가 존재하는 경우 YES, 아니면 NO를 출력하라.
//ex. input : 6 \n 1 3 5 6 7 10
//    output : YES

#include <iostream>
using namespace std;

int n, arr[11], total=0;
bool flag=false;

void DFS(int x, int sum)
{
	if(flag==true) return;
	if(x==n+1){
		if(sum==(total-sum))
			flag=true;
		
	}
	else
	{
		DFS(x+1, sum+arr[x]);
		DFS(x+1, sum);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		total+=arr[i];
	}
	DFS(1,0);
	if(flag) printf("YES");
	else printf("NO");
}