// 문제 59번. 자연수 N이 주어지면 1부터 N까지를 원소로 갖는 집합의 부분집합을 모두 출력. 단, 공집합은 출력하지 않음.
// ex. input : 3
// output : 
// 1 2 3
// 1 2
// 1 3
// 1
// 2 3
// 2
// 3


#include <iostream>
using namespace std;

int n,ch[11]={0,};

void DFS(int x)
{
	if(x==n+1) 
	{
		for(int i=1;i<=n;i++)
			if(ch[i]==1)
				printf("%d ",i);
		printf("\n");		
	}
	
	else{
		ch[x]=1;
		DFS(x+1);
		ch[x]=0;
		DFS(x+1);
	}
}

int main()
{
	scanf("%d",&n);
	DFS(1);
}