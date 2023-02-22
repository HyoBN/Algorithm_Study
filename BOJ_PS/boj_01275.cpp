#include <iostream>
#include <cmath>
using namespace std;

int n,q;
long long arr[100001];
long long segTree[400004];

long long init(int start, int end, int nodeNum){
    if(start == end)
        return segTree[nodeNum] = arr[start];
    int mid = (start+end)/2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

long long subSum(int nodeNum, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return segTree[nodeNum];
    }
    int mid = (start+end)/2;
    return (subSum(nodeNum * 2, start, mid, left, right) + subSum(nodeNum * 2 + 1, mid + 1, end, left, right));
}

void update(int start, int end, int nodeNum, int targetIdx, long long value){
    if(targetIdx<start || targetIdx>end) return;
    segTree[nodeNum]+=value;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start, mid, nodeNum * 2, targetIdx, value);
    update(mid+1, end, nodeNum * 2+1, targetIdx, value);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    init(0,n-1,1);

    for(int i=0;i<q;i++){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<subSum(1,0,n-1,min(a-1,b-1),max(a-1,b-1))<<"\n";
        update(0,n-1,1,c-1,d-arr[c-1]);
        arr[c-1]=d;
    }
}
