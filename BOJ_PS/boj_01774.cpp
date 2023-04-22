#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge{
    int n1,n2;
    double cost;

    Edge(int a, int b, double c) {
        n1=a,n2=b,cost=c;
    }

    bool operator<(Edge &other){
        return cost<other.cost;
    }
};

int parents[1001];
vector<pair<int,int>> nodes;
vector<Edge> edges;
double ans=0;

double getDistance(pair<int, int> a, pair<int, int> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int Find(int x){
    if(x==parents[x]) return x;
    else{
        return parents[x] = Find(parents[x]);
    }
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x==y) return false;
    else{
        parents[x]=y;
        return true;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        nodes.push_back({x, y});
    }

    for(int i=0;i<n;i++){
        parents[i]=i;
    }

    for (int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        Union(x-1, y-1); //0번부터 시작했기 때문.
    }

    for(int i=0;i<n-1;i++){
        for (int j = i + 1; j < n; j++) {
            if(Find(i)!=Find(j)) {
                double dist = getDistance(nodes[i], nodes[j]);
                edges.push_back(Edge(i, j, dist));
            }
        }
    }
    sort(edges.begin(), edges.end());


    for (int i = 0; i < edges.size(); i++) {
        Edge tmp = edges[i];
        int node1 = tmp.n1;
        int node2 = tmp.n2;

        if(Find(node1)!=Find(node2)){
            Union(node1, node2);
            ans+=tmp.cost;
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ans;
}
