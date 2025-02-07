#include <iostream>
#include <vector>
using namespace std;

int n, m, k,ans;
int parents[51];
vector<int> knowPeople;
vector<int> party[50];

int Find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}

int main() {
    cin >> n >> m >> k;
    while (k--) {
        int t;
        cin >> t;
        knowPeople.push_back(t);
    }

    for (int i = 1; i <= n; i++) parents[i] = i;

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int num,prev;
        for (int j = 0; j < p; j++) {
            prev = num;
            cin>>num;
            if (j >= 1) {
                Union(prev, num);
            }
            party[i].push_back(num);
        }
    }

    for(int i=0;i<m;i++){
        bool flag = false;
        for(int j=0;j<party[i].size();j++){
            if (flag) break;
            for(int k=0;k<knowPeople.size();k++){
                if(Find(party[i][j]) == Find(knowPeople[k])){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)ans++;
    }

    cout << m-ans;

    return 0;
}
