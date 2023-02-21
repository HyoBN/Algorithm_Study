#include <iostream>
using namespace std;

int n,m,k;
long long arr[1000001];
long long tree[4000004];

long long init(int start, int end, int num){
    if (start == end) {
        return tree[num] = arr[start];
    }
    int mid = (start+end)/2;
    return tree[num] = init(start, mid, num * 2) + init(mid + 1, end, num * 2 + 1);
}

long long subSum(int start, int end, int num, int left, int right){
    if(left>end || right < start)
        return 0;
    if(left <=start && end<=right)
        return tree[num];
    int mid = (start+end)/2;
    return subSum(start, mid, num * 2, left, right) + subSum(mid + 1, end, num * 2 + 1, left, right);
}

void update(int start, int end, int num, int idx, long long value){
    if(idx < start || end < idx)
        return;
    tree[num] +=value;
    if(start == end) return;
    int mid = (start + end)/2;
    update(start, mid, num * 2, idx, value);
    update(mid + 1, end, num * 2 + 1, idx, value);
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    init(0, n - 1, 1);

    long long a,b,c;
    for (int i = 0; i < m + k; i++) {
        cin>>a>>b>>c;
        if(a==1){
            long long tmp=c-arr[b-1];
            arr[b-1]=c;
            update(0, n - 1, 1, b - 1, tmp);
        }else{
            cout<<subSum(0,n-1,1,b-1,c-1)<<endl;
        }
    }
}
