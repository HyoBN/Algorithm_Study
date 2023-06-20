#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct bottles{
    int a,b,c;
};

int A,B,C;
bool visited[201][201][201];

int main(){
    queue<bottles> q;
    vector<int> ans;
    cin>>A>>B>>C;
    q.push({0, 0, C});

    while (!q.empty()) {
        bottles tmp = q.front();
        int a = tmp.a, b = tmp.b, c = tmp.c;
        q.pop();
        if (visited[a][b][c]) {
            continue;
        }
        visited[a][b][c]=true;

        if(a==0) ans.push_back(c);

        if(a+b>B){
            q.push({a + b - B, B, c});
        }else{
            q.push({0, a + b, c});
        }

        if(a+c>C){
            q.push({a + b - C, b, C});
        }else{
            q.push({0, b, a + c});
        }

        if(b+a>A){
            q.push({A, b + a - A, c});
        }else{
            q.push({b + a, 0, c});
        }

        if(b+c>C){
            q.push({a, b + c - C, C});
        }else{
            q.push({a, 0, b + c});
        }

        if(c+a>A){
            q.push({A, b, c + a - A});
        }else{
            q.push({c + a, b, 0});
        }
        if(c+b>B){
            q.push({a, B, c + b - B});
        }else{
            q.push({a, c + b, 0});
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
