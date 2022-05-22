#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	queue<pair<long long,int>> q;
	long long a,b;
	int ans=-1;
	cin>>a>>b;
	
	q.push({a,1});
	while(!q.empty()){
		long long tmp=q.front().first;
		int cnt=q.front().second;
		q.pop();
		if(tmp==b){
			ans=cnt;
			break;
		}
		if(tmp*2<=b)
			q.push({tmp*2,cnt+1});
		if(tmp*10+1<=b)
			q.push({tmp*10+1,cnt+1});
	}
	cout<<ans;
}