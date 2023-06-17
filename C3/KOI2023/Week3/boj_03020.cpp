#include<iostream>
using namespace std;

int n, h, cnt=0;
int top[500001];
int bottom[500001];
int sum[500001];
int inf = 2147000000;

int main()
{
    cin >> n >> h;
    for (int i = 0; i < n / 2; i++)
    {
        int a, b;
        cin >> a >> b;
        bottom[a]++;
        top[h + 1 - b]++;
    }
    for (int i = h - 1; i > 0; i--)
    {
        bottom[i] += bottom[i + 1];
    }
    for (int i = 1; i <= h; i++)
    {
        top[i] += top[i - 1];
        sum[i] += top[i] + bottom[i];
        if (sum[i] < inf)
        {
            cnt = 1;
            inf = sum[i];
        }
        else if (sum[i] == inf) {
            cnt++;
        }
    }
    cout << inf << ' ' << cnt;
}
