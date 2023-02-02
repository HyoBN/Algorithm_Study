#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans, cur;
vector<pair<int, int>> v;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x,a, b;
		cin >> x >> a >> b;
		v.push_back({ a,1 });
		v.push_back({ b,-1 });
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		cur += v[i].second;
		ans = max(cur, ans);
	}
	cout << ans;
}
