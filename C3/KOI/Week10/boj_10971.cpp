#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w[20][20];
int main() {
	int n;
	int ans = 2147000000;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	vector<int> d(n);
	for (int i = 0; i < n; i++)
		d[i] = i;

	do {
		bool flag = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (w[d[i]][d[i + 1]] == 0) {
				flag = false;
			}
			else
				sum += w[d[i]][d[i + 1]];
		}
		if (flag && w[d[n - 1]][d[0]] != 0) {
			sum += w[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(d.begin(), d.end()));

	cout << ans;

}
