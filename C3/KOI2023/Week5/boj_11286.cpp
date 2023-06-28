#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)>abs(b))
            return true;
        else if(abs(a)==abs(b)){
            if(a>b) return true;
            else return false;
        }
        return false;
    }
};

int main(){
    int n;
    priority_queue<int,vector<int>,cmp> pq;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        if(tmp!=0) pq.push(tmp);
        else{
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top()<<'\n';
                pq.pop();
            }
        }
    }
}
