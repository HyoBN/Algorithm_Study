#include <iostream>
using namespace std;

int main()
{
    int n, s;
    int arr[51];
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> s;

    int first = 0;
    while (first < n && s > 0) {
        int tmp = first;

        for (int i = first; i <= min(n - 1, first + s); i++) {
            if (arr[tmp] < arr[i])
                tmp = i;
        }
        for (int i=tmp; i > first; i--) {
            swap(arr[i-1],arr[i]);
            s--;
        }
        first++;
    }

    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
