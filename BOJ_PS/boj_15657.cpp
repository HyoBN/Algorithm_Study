#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
vector<int> v;
void dfs(int start, int cnt){
    if(cnt>m) {
        for (int i = 0; i < v.size(); i++) {
            cout<<v[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for (int i = start; i < n; i++) {
        v.push_back(arr[i]);
        dfs(i, cnt + 1);
        v.pop_back();
    }
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0,1);

}
