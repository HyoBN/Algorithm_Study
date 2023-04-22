#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge{
    int n1,n2;
    double cost;

    Edge(int a, int b, double c){
        n1=a,n2=b,cost=c;
    }
    bool operator<(Edge &other){
        return cost<other.cost;
    }
};

vector<pair<double,double>> nodes;
int parents[101];
int n;
double ans=0.00;

double calc_distance(pair<double, double> n1, pair<double, double> n2){
    return sqrt(pow(n1.first-n2.first,2) +pow(n1.second-n2.second,2));
}

int Find(int x){
    if(x == parents[x])
        return x;
    else
        return parents[x] = Find(parents[x]);
}

bool Union(int x, int y){
    x=Find(x);
    y= Find(y);
    if(x==y) return false;
    else{
        parents[x]=y;
        return true;
    }
}

int main(){

    scanf("%d",&n);

    for (int i = 1; i <= n; i++) {
        double x,y;
        scanf("%lf %lf", &x, &y);
        nodes.push_back({x, y});
    }

    vector<Edge> a;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double distance = calc_distance(nodes[i], nodes[j]);
            a.push_back(Edge(i, j, distance));

        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i <= n; i++) {
        parents[i]=i;
    }

    for (int i = 0; i < a.size(); i++) {
        Edge tmp = a[i];
        int x = Find(tmp.n1);
        int y = Find(tmp.n2);
        if (x != y) {
            if(Union(tmp.n1, tmp.n2))
                ans += tmp.cost;
        }
    }
    printf("%.2lf", ans);
}
