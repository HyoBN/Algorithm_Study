#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001];
int f,s,g,u,d;
queue<pair<int,int>> q;

int main()
{
	bool flag=false;
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);

	visited[s]=true;
	q.push({s,0});
	
	while(!q.empty())
	{
		int now=q.front().first;
		int cnt=q.front().second;
		
		if(now==g){
			flag=true;
			break;
		}
		q.pop();
		
		if(now+u<=f && !visited[now+u]){
			visited[now+u]=true;
			q.push({now+u,cnt+1});
		}
		
		if(now-d>=1 && !visited[now-d]){
			visited[now-d]=true;
			q.push({now-d,cnt+1});
		}
		
	}
	if(!flag) printf("use the stairs");
	else printf("%d",q.front().second);
}