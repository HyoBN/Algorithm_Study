#include <iostream>
using namespace std;

int dist[501][501];
int n, m;
int cnt = 0;
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if(dist[i][k]==1){
				for (int j = 1; j <= n; j++) {
					if (dist[k][j] == 1) {
						dist[i][j] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		bool cantKnow = false;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else if (dist[i][j] == 0 && dist[j][i] == 0) {
				cantKnow = true;
				break;
			}
		}
		if (!cantKnow) cnt++;
	}
	cout << cnt;

}
