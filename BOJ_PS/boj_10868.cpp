#include <iostream>
using namespace std;

int n,m;
int arr[100001];
int minTree[400004];

int minInit(int start, int end, int nodeNum){
    if(start == end){
        return minTree[nodeNum]=arr[start];
    }
    int mid = (start+end)/2;
    return minTree[nodeNum] = min(minInit(start, mid, nodeNum*2),minInit(mid+1,end,nodeNum*2+1));
}

int mini(int start, int end, int nodeNum, int left, int right){
    if(left>end || right < start)
        return 1000000001;
    if(left <=start && end<=right)
        return minTree[nodeNum];
    int mid = (start+end)/2;
    return min(mini(start, mid, nodeNum * 2, left, right), mini(mid + 1, end, nodeNum * 2 + 1, left, right));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    minInit(0, n - 1, 1);

    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        cout<<mini(0, n - 1, 1, a - 1, b - 1)<<"\n";
    }
}
