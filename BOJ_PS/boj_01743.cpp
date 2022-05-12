#include <iostream>
using namespace std;

int n,m;
int cnt=0,ans=0;
int map[101][101];
bool visited[101][101];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

void dfs(int y,int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>0 && ny<=n && nx>0 && nx<=m){
			if(map[ny][nx]==1 && !visited[ny][nx]){
				cnt++;
				dfs(ny,nx);
			}
		}
	}
}

int main(){
	int k;
	cin>>n>>m>>k;
	
	while(k--){
		int y,x;
		cin>>y>>x;
		map[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==1 && !visited[i][j]){
				cnt=1;
				dfs(i,j);
				if(ans<cnt) ans=cnt;
			}
		}
	}
	cout<<ans;
}