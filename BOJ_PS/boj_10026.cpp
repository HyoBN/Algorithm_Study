#include <iostream>
using namespace std;

int n;
char target;
char map[101][101];
bool visited1[101][101];
bool visited2[101][101];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

void dfs1(int y, int x, char target){
	
	visited1[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<n && nx>=0 && nx<n){
			if(map[ny][nx]==target && !visited1[ny][nx])
				dfs1(ny,nx,target);
		}
	}
	
}

void dfs2(int y, int x, char target){
	visited2[y][x]=true;
	char tmp='x';
	if(target=='G') tmp='R';
	else if(target=='R') tmp='G';
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<n && nx>=0 && nx<n){
			if((map[ny][nx]==target || map[ny][nx]==tmp) && !visited2[ny][nx])
				dfs2(ny,nx,target);
		}
	}
}

int main(){
	int area1=0,area2=0;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited1[i][j]){
				area1++;
				dfs1(i,j,map[i][j]);
			}
			if(!visited2[i][j]){
				area2++;
				dfs2(i,j,map[i][j]);
			}
		}
	}
	cout<<area1<<' '<<area2;
}