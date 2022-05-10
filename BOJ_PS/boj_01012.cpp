#include <iostream>
#include <cstring>
using namespace std;

int m,n;
int map[51][51];
bool visited[51][51];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

void dfs(int i,int j){
	visited[i][j]=true;
	for(int t=0;t<4;t++){
		int ny=i+y_dir[t];
		int nx=j+x_dir[t];
		if(ny<n && ny>=0 && nx<m && nx>=0){
			if(map[ny][nx]==1 && !visited[ny][nx]){
				dfs(ny,nx);
			}
		}
	}
}

int main(){
	int t,k;
	int x,y;
	
	cin>>t;
	while(t--){
		int ans=0;
		cin>>m>>n>>k;
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));

		for(int i=0;i<k;i++){
			cin>>x>>y;
			map[y][x]=1;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==1 && !visited[i][j]){
					ans++;
					dfs(i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
}