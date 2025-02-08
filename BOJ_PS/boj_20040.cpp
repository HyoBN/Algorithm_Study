#include <iostream>
using namespace std;

int root[500001];
int n,m,ans;

int findRoot(int x){
    if(x==root[x]){
        return x;
    } else{
        return root[x]=findRoot(root[x]);
    }
}

void unionNode(int a, int b){
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra!=rb){
        ra>rb ? root[ra] = rb : root[rb] = ra;
    }
}

bool isUnion(int a, int b){
    if(findRoot(a) == findRoot(b))
        return true;
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        root[i]=i;
    }


    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b;
        if(a>b){
            c=a;
            a=b;
            b=c;
        }

        if(isUnion(a,b)){
            ans=i;
            break;
        }
        else unionNode(a,b);

    }

    cout<<ans;
}
