#include <iostream>
#include <cmath>
using namespace std;

int n,m,tmp,cnt=0,mmax=0;
int y_dir[]={1,0,-1,0};
int x_dir[]={0,1,0,-1};
bool visited[501][501];
bool map[501][501];

void dfs(int y,int x){
	visited[y][x]=true;
	tmp++;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<n && nx>=0 && nx<m){
			if(!visited[ny][nx] && map[ny][nx]){
				dfs(ny,nx);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j] && map[i][j]){
				cnt++;
				tmp=0;
				dfs(i,j);
				mmax=max(mmax,tmp);
			}
		}
	}
	cout<<cnt<<'\n'<<mmax;
}
