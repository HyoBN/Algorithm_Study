#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int n1,n2,cost;

    Edge(int a, int b, int c){
        n1=a,n2=b,cost=c;
    }

    bool operator<(Edge &other){
        return cost < other.cost;
    }
};

vector<Edge> edges;
int parents[1001];
int n,m,k;
int ans=0;

int Find(int x){
    if (x == parents[x]) {
        return x;
    }
    else{
        return parents[x] = Find(parents[x]);
    }
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    parents[y]=x;
}

bool isUnion(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x==y) return true;
    return false;
}

int main(){
    cin>>n>>m>>k;
    vector<int> powerPlant;
    for(int i=0;i<=n;i++){
        parents[i]=i;
    }

    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        powerPlant.push_back(tmp);
    }
    for(int i=1;i<k;i++){
        Union(powerPlant[i - 1], powerPlant[i]);
    }

    for (int i = 0; i < m; i++) {
        int x,y,c;
        cin>>x>>y>>c;
        edges.push_back(Edge(x, y, c));
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        Edge tmp = edges[i];
        if(!isUnion(tmp.n1,tmp.n2)){
            ans+=tmp.cost;
            Union(tmp.n1,tmp.n2);
        }
    }
    cout<<ans;
}
