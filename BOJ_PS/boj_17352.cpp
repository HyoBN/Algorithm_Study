#include <iostream>
using namespace std;

int root[300001];
int n;


int find(int x){
    if(root[x]==x){
        return x;
    }
    else{
        return root[x] = find(root[x]);
    }
}

void merge(int a, int b){
    int ra = find(a);
    int rb = find(b);

    if(ra!=rb){
        root[ra]=rb;
    }
}

bool isUnion(int a, int b){
    if(find(a)==find(b)) {
        return true;
    }
    return false;
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        root[i]=i;
    }

    for(int i=0;i<n-2;i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for(int i=2;i<=n;i++){
        if (!isUnion(1,i)) {
            cout << "1 " << i;
            return 0;
        }
    }

}
