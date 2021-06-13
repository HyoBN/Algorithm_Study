#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long long ans[100] = { 0,1,1, };
	
	if (n < 3) 
		cout << ans[n];
	else
	{
		for (int i = 3; i <= n; i++)
			ans[i] = ans[i - 2] + ans[i - 1];
	
		cout << ans[n];
	}
}