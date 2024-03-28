#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,sum=0,cnt=0;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    while (sum>0){
        bool flag = true;
        for (int i = 0; i < n; i++){
            if (v[i] % 2){
                flag = false;
                v[i]--;
                cnt++;
                sum--;
            }
        }
        if (flag){
            for (int i = 0; i < v.size(); i++){
                v[i] /= 2;
                sum -= v[i];
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
}
