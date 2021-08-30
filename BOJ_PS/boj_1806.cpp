#include <iostream>
using namespace std;

int main() {
	int n;
	long long arr[100001];
	long long s;
	long long sum = 0;
	scanf("%d %lld",&n,&s);
	for (int i = 0; i < n; i++)
		scanf("%lld",&arr[i]);

	int low=0,high=0,len=0,res=1000000;

	while (true) {

		if (sum < s) {
			if (high > n-1) break;
			sum += arr[high++];
			len++;
		}
		else {
			if (len < res) res = len;
			sum -= arr[low++];
			len--;
		}
	}
	printf("%d",res==1000000 ? 0 : res);
	

	return 0;
}
