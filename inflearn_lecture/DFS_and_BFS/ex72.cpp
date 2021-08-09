// 문제 72. 조세푸스 문제. n명, k번째.
//ex, input : 1000 9
//    output : 329
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n,k;
	int tmp,cnt=0;
	queue<int> q;
	scanf("%d %d",&n,&k);
	
	for(int i=1;i<=n;i++)
		q.push(i);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		cnt++;
		if(cnt==k)
			cnt=0;
		else
			q.push(tmp);
	}
	printf("%d",tmp);
}