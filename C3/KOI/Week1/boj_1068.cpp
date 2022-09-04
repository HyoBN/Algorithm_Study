#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int n, root, ans, x;

void dfs(int cur) {
	if (cur == x) return;
	int ok = 0;
	for (int i = 0; i < tree[cur].size(); i++) {
		if (tree[cur][i] == x) continue;
		dfs(tree[cur][i]);
		ok++;
	}
	if (ok == 0) ans++;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == -1) {
			root = i;
			continue;
		}
		tree[x].push_back(i);
	}
	scanf("%d", &x);
	tree[x].clear();
	dfs(root);
	printf("%d\n", ans);
	return 0;
}
