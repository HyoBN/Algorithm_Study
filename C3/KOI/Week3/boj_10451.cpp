#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int arr[1001];
bool visited[1001];

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	dfs(arr[x]);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = false;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				ans++;
			}
		}
		cout << ans;
	}
}
