#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int y_dir[]={-2,-2,0,0,2,2};
int x_dir[]={-1,1,-2,2,-1,1};
bool visited[201][201];
int main(){
	int n,ans=-1;
	int r1,c1,r2,c2;
	pair<int, int> now,goal;
	queue<pair<pair<int,int>,int>> q;
	cin>>n;
	cin>>r1>>c1>>r2>>c2;
	now={r1,c1};
	goal={r2,c2};
	q.push({now,0});
	visited[now.first][now.second]=true;
	while(!q.empty()){
		pair<pair<int,int>,int> tmp=q.front();
		q.pop();
		int y=tmp.first.first;
		int x=tmp.first.second;
		visited[y][x]=true;
		if(tmp.first==goal){
			ans=tmp.second;
			break;
		}
		for(int i=0;i<6;i++){
			int ny=y+y_dir[i];
			int nx=x+x_dir[i];
			if(ny>=0 && ny< n && nx>=0 && nx<n){
				if(!visited[ny][nx]){
					visited[ny][nx]=true;
					q.push({{ny,nx},tmp.second+1});
				}
			}
		}
		
	}
	cout<<ans;
}
