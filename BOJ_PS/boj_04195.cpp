#include <iostream>
#include <map>
using namespace std;

int root[200002];
int amount[200002];

int find(int a){
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}

void merge(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if(rootA != rootB){
        if(amount[rootA]>amount[rootB]){
            root[rootB] = rootA;
            amount[rootA] += amount[rootB];
        }else {
            root[rootA] = rootB;
            amount[rootB] += amount[rootA];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int f,node=0;
        map<string,int> friends;
        cin>>f;

        for(int i=0;i<2*f;i++) {
            root[i] = i;
            amount[i] = 1;
        }

        while(f--){
            string f1,f2;
            cin>>f1>>f2;
            if(friends.count(f1)==0) friends[f1]=node++;
            if(friends.count(f2)==0) friends[f2]=node++;
            merge(friends[f1],friends[f2]);

            int a1,a2;
            a1=amount[find(friends[f1])];
            a2=amount[find(friends[f2])];
            cout<<max(a1,a2)<<"\n";
        }
    }
}
