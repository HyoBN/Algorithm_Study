#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> v;
int n, s,x;
long long ans;
map<int, int> mp;

void dfs(int idx, int sum){
	if(idx == n/2)
		mp[sum]++;
	else{
		dfs(idx+1, sum);
		dfs(idx+1, sum + v[idx]);
	}
}

void check_dfs(int idx, int sum){
	if(idx == n)
		ans += mp[s-sum];
	else{
		check_dfs(idx+1, sum);
		check_dfs(idx+1, sum + v[idx]);
	}
}

int main(){
	scanf("%d %d",&n,&s);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		v.push_back(x);
	}
	dfs(0, 0);
	check_dfs(n/2, 0);
	if(s == 0) ans--;
	printf("%lld",ans);
}