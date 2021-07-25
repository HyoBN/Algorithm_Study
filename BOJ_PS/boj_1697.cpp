#include <queue>
#include <iostream>
using namespace std;

int n, k;
int arr[100001];
queue<int> q;

int bfs() {
	q.push(n);
	arr[n] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k)
			return arr[p] -1 ;

		if (p - 1 >= 0 && arr[p - 1] == 0) {
			q.push(p - 1);
			arr[p - 1] = arr[p] + 1;
		}
		if (p + 1 <= 100000 && arr[p + 1] == 0) {
			q.push(p + 1);
			arr[p + 1] = arr[p] + 1;
		}
		if (p * 2 <= 100000 && arr[2*p] == 0) {
			q.push(p * 2);
			arr[p * 2] = arr[p] + 1;
		}
	}
}
int main() {
	cin >> n >> k;
	
	cout << bfs();

	return 0;
}