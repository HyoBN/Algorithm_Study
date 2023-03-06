#include <iostream>
using namespace std;

int n,m;
int root[1000001];

int find(int a){
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}

void merge(int a, int b){
    int parentA = find(a);
    int parentB = find(b);
    if(parentA != parentB) root[parentA]=b;
    else return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<1000001;i++){
        root[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0) merge(b,c);
        else{
            if(find(b)==find(c))
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
