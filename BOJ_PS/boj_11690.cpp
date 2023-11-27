#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long ans=1;
bool notPrime[100000001];
void primeNum(int num){
    for (int i = 2; i*i < num; i++) {
        if(notPrime[i]) continue;
        for (int j = i * i; j <= num; j += i) {
            notPrime[j]=true;
        }
    }
}

int main(){
    cin>>n;
    primeNum(n);

    long long mod = pow(2, 32);
    vector<int> v;
    v.push_back(2);

    for (int i = 3; i <= n; i+=2) {
        if(!notPrime[i]) v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        long long tmp = v[i];
        while (tmp <= n) {
            tmp*=v[i];
        }
        tmp /= v[i];
        ans = (ans * tmp) % mod;
    }
    cout << ans;
}
