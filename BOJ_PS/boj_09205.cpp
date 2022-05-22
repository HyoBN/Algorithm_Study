#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

bool visited[101];
int main(){
	int t,n,x,y;
	
	cin>>t;
	while(t--){
		memset(visited,false,sizeof(visited));
		pair<int,int> now,festival;
		pair<int,int> arr[101];
		queue<pair<int,int>> q;
		bool isAble=false;
		cin>>n;
		cin>>x>>y;
		now={x,y};
		q.push(now);
		for(int i=0;i<n;i++){
			cin>>x>>y;
			arr[i]={x,y};
		}
		cin>>x>>y;
		festival={x,y};

		while(!q.empty()){
			pair<int,int> tmp=q.front();
			q.pop();
			if(abs(festival.first-tmp.first)+abs(festival.second-tmp.second)<=1000){
				isAble=true;
				break;
			}
			for(int i=0;i<n;i++){
				if(!visited[i] && abs(arr[i].first-tmp.first)+abs(arr[i].second-
				   tmp.second)<=1000){
					visited[i]=true;
					q.push(arr[i]);
				}
			}
		}
		cout<<(isAble==true ? "happy" : "sad")<<endl;
	}
	
}