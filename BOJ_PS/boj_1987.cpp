#include <iostream>
#include <string>
using namespace std;

int r,c,res=0;
bool alpha_visited[26];
int y_arr[4]={1,0,-1,0};
int x_arr[4]={0,1,0,-1};
string s[21];

void DFS(int y, int x, int cnt){
	
	
	for(int i=0;i<4;i++){
		int ny=y+y_arr[i];
		int nx=x+x_arr[i];
		if(ny>=0 && ny<r && nx>=0 && nx<c){
			if(!alpha_visited[s[ny][nx]-65]){
				alpha_visited[s[ny][nx]-65]=true;
				DFS(ny,nx,cnt+1);
				alpha_visited[s[ny][nx]-65]=false;
			}
		}
		
	}
	res=max(cnt,res);
	return;
}

int main()
{

	cin>>r>>c;
	for(int i=0;i<r;i++)
		cin>>s[i];
	alpha_visited[s[0][0]-65]=true;
	DFS(0,0,1);
	
	cout<<res;
	
}