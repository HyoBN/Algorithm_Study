#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n,h;
	stack<pair<int,int>> s;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h);
		while(!s.empty())
		{
			if(s.top().second>h){
				printf("%d ",s.top().first);
				break;
			}
			s.pop();
		}
		if(s.empty())
			printf("0 ");
		s.push({i,h});
	}
}