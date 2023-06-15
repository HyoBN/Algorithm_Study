#include <iostream>
using namespace std;

int n;
int arr[100001];
int a, b;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;
    a = arr[0];
    b = arr[n - 1];
    int temp = 0;
    int min = abs(a + b);

    while (left < right) {
        temp = arr[left] + arr[right];
        if (abs(temp) < min) {
            min = abs(temp);
            a = arr[left];
            b = arr[right];
        }
        if (temp == 0) {
            break;
        }
        if (temp > 0) {
            right--;
        } else {
            left++;
        }
    }
    cout << a << " " << b;
    return 0;
}
