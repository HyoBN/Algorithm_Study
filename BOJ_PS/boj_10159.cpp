#include <iostream>
using namespace std;

bool dist[101][101];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = true;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i][k]) {
				for (int j = 1; j <= n; j++) {
					if(dist[k][j])
						dist[i][j] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] || dist[j][i]) {
				cnt++;
			}
		}
		cout << n - cnt-1 << endl;
	}
}
