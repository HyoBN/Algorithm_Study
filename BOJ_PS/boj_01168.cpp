#include <iostream>
using namespace std;

int n,k,index=1;
int segTree[400000];

int init(int node, int start, int end){
    if(start==end) return segTree[node]=1;
    int mid = (start+end)/2;
    return segTree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

int update(int node, int start, int end, int deleteNode){
    segTree[node]--;
    if(start==end) return 0;
    else{
        int mid=(start+end)/2;
        if(deleteNode <= mid) return update(2 * node, start, mid, deleteNode);
        else return update(2 * node + 1, mid + 1, end, deleteNode);
    }
}

int query(int node, int start, int end, int order){
    if(start==end) return start;
    int mid=(start+end)/2;
    if(order<=segTree[node*2]) return query(node*2, start, mid, order);
    else return query(2 * node + 1, mid + 1, end, order - segTree[node * 2]);
}
int main(){
    cin>>n>>k;

    init(1, 1, n);
    cout<<"<";

    for (int i = 0; i < n; i++) {
        int size=n-i;
        index +=k-1;

        if(index % size ==0) index=size;
        else if(index>size) index %= size;

        int num = query(1, 1, n, index);
        update(1, 1, n, num);

        cout<<num;
        if(i!=n-1)
            cout<<", ";
    }
    cout<<">";
}
