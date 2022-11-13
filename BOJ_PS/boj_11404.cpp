#include <iostream>
#include <cmath>
using namespace std;

#define INF 20000000

int dist[101][101];

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b],c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i][k] != INF) {
				for (int j = 1; j <= n; j++) {
					if (i != j)
						dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}
