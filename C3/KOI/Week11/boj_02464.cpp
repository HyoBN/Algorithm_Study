#include <iostream>
#include <algorithm>
using namespace std;

int d[64];
unsigned long long x, y;

void toDecimal() {
	for (int i = 0; i < 64; i++) {
		x *= 2;
		x += d[i];
	}
}

int main() {
	cin >> x;
	y = x;
	for (int i = 0; i < 64; i++) {
		d[63 - i] = x % 2;
		x /= 2;
	}

	prev_permutation(d, d + 64);
	toDecimal();
	cout << (x > y ? 0 : x)<<" ";

	next_permutation(d, d + 64);
	next_permutation(d, d + 64);
	x = 0;
	toDecimal();
	cout << x;
}
