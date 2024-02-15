#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n,tmp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    cout << v[(n-1)/2];
}
