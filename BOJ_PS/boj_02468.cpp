#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int depth,ans,area;
int map[101][101];
bool visited[101][101];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

void dfs(int y, int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<n && nx>=0 && nx<n){
			if(map[ny][nx]>depth && !visited[ny][nx]){
				dfs(ny,nx);
			}
		}
	}
}

int main(){
	bool flag=true;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	
	while(flag){
		flag=false;
		
		area=0;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]>depth && !visited[i][j]){
					flag=true;
					area++;
					dfs(i,j);
				}
			}
		}
		ans=max(ans,area);
		depth++;
	}
	cout<<ans;
}