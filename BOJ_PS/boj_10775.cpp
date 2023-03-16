#include <iostream>
using namespace std;

int root[100001];

int find(int a){
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}

void merge(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    root[rootA]=rootB;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g,p,x,ans=0;
    cin>>g>>p;
    for(int i=1;i<=g;i++)
        root[i]=i;

    while(p--){
        cin>>x;
        if(find(x)==0) break;
        else{
            ans++;
            merge(find(x),find(x)-1);
        }
    }
    cout<<ans;
}
