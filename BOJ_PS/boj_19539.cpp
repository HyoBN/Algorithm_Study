#include<iostream>
using namespace std;

int n, totalHeight, twoAmount;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		totalHeight += a;
		twoAmount += (a / 2);
	}
	if (totalHeight % 3 == 0 && twoAmount >= (totalHeight / 3))
		cout << "YES";
	else
		cout << "NO";
}
