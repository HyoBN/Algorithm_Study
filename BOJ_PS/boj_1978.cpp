#include <iostream>
using namespace std;

int main()
{
	int num;
	int count, result = 0;
	cin >> num;

	int arr[1001];

	for (int i = 0; i < num; i++)
	{
		count = 0;
		cin >> arr[i];

		for (int j = 1; j <= arr[i]; j++)
			if (arr[i] % j == 0)
				count++;
		if (count == 2)  
			result++;
		
	}
	cout << result;
	return 0;
}