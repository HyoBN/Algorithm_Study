#include <iostream>
using namespace std;

int root[201];
int arr[201][201];
int plan[1001];

int find(int a){
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}

void merge(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    root[rootA]=rootB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<201;i++)
        root[i]=i;

    int n, m,tmp;

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (arr[i][j] == 1)
                merge(i, j);
        }
    }

    for (int i = 0; i < m; i++)
        cin >> plan[i];
    tmp = find(plan[0]);
    for (int i = 1; i < m; i++)
        if (find(plan[i]) != tmp) {
            cout << "NO";
            return 0;
        }
    cout<<"YES";
}
