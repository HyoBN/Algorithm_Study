#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> v[10];

bool isPrime(int num){
    if(num<2) return false;
    int a = (int) sqrt(num);
    for (int i = 2; i <= a; i++) {
        if(num%i==0) return false;
    }
    return true;
}

void backTracking(int cnt){
    if(cnt>n){
        for(int i=0;i<v[n].size();i++){
            cout << v[n][i] << '\n';
        }
        return;
    }
    for(int i=0;i<v[cnt].size();i++) {
        for (int j = 1; j < 10; j++) {
            int nextNum = v[cnt][i]*10+j;
            if (isPrime(nextNum)) {
                v[cnt + 1].push_back(nextNum);
            }
        }
    }
    backTracking(cnt + 1);
}

int main(){
    cin>>n;
    v[1]={2,3,5,7};
    backTracking(1);
}
