#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long ans=0;
    int tmp=0;
    int arr[100001];

    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr + n+1);

    for (int i = 1; i <= n; i++) {
        if(arr[i]<=tmp){
            continue;
        }
        tmp++;
        if(arr[i]>tmp){
            ans += arr[i] - tmp;
        }
    }
    cout<<ans;

}
