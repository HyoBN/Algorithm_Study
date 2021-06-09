#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int n;
    cin >> n;
    
    for (int i=5; i<=n; i=i*5)
        count += (n/i);
        
    cout << count;
}