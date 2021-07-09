#include <iostream>
#include <vector>
using namespace std;
 
pair<long long, long long> zero(long long n)
{
        long long two = 0, five = 0;
        for (long long i = 2; i <= n; i *= 2)
                 two += n / i;
        for (long long i = 5; i <= n; i *= 5)
                 five += n / i;
        return { two, five };
}

int main(void)
{
        long long n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> p(3);
        p[0] = zero(n);
        p[1] = zero(m); 
        p[2] = zero(n - m); 
        cout << min(p[0].first-p[1].first-p[2].first, p[0].second-p[1].second-p[2].second);
        return 0;
}