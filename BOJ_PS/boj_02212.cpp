#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sensor[10001];
int main() {
	int n, k,tmp,ans=0;
	vector<int> dist;
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++)
		cin >> sensor[i];

	sort(sensor, sensor + n);
	for (int i = 0; i < n - 1; i++)
		dist.push_back(sensor[i + 1] - sensor[i]);

	sort(dist.begin(), dist.end());
	for (int i = 0; i < n - k; i++) {
		ans += dist[i];
	}
	cout << ans;
}
