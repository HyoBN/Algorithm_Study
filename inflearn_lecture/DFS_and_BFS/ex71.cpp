// 문제 71. 직선 상에서 시작점(s)을 기준으로 -1,1,5로만 움직여 도착점(e)에 도착하는 최소 이동 횟수를 구하라.
// ex. input : 5 14
//     output : 3

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int s,e,tmp,pos;
	int d[3]={-1,1,5};
	queue<int> q;
	vector<int> vec;
	int answer[10001];
	scanf("%d %d",&s,&e);
	answer[s]=1;
	q.push(s);
	
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=0;i<3;i++)
		{
			pos=tmp+d[i];
			if(pos<0 || pos>10000)
				continue;
			if(pos==e)
			{
				printf("%d",answer[tmp]);
				exit(0);
			}
			if(answer[pos]==0)
			{
				answer[pos]=answer[tmp]+1;
				q.push(pos);
			}
		}
		
	}
}