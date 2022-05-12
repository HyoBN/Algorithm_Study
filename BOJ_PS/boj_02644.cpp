#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
bool visited[101];
int cnt[101];

int main(){
	int n,m,a,b;
	queue<int> q;
	cin>>n;
	cin>>a>>b;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		map[x][y]=1;
		map[y][x]=1;
	}
	q.push(a);
	visited[a]=true;
	
	while(!q.empty()){
        a=q.front();
        q.pop();
		
		for(int i=1;i<=n;i++){
			if(map[a][i]==1 && !visited[i]){
				visited[i]=true;
				q.push(i);
				cnt[i]=cnt[a]+1;
			}
		}
    }
	cout<<(cnt[b]==0 ? -1 : cnt[b]);
}