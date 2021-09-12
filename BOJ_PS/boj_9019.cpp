#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
 
bool visited[10001];
 
int D(int x){
	return (x<<1)%10000;
}

int S(int n) {
    if (n == 0) return 9999;
    return n - 1;
}
int L(int n) {
    int a = n / 1000;
    int b = (n % 1000) * 10;
    return b + a;
}
int R(int n) {
    int a = (n % 10);
    int b = (n / 10);
 
    return (a * 1000) + b;
}

int main()
{
    int t;
	int (*fp[4])(int)={D,S,L,R};
	char command[4]={'D','S','L','R'};
	cin>>t;
	
    while (t--) {
        int a, b;
		cin>>a>>b;
        queue<pair<int, string> >q;
		
        memset(visited, false, sizeof(visited));
        q.push(make_pair(a, ""));
		
        while (!q.empty()) {
            int num = q.front().first;
            string k = q.front().second;
            
            if (num == b) {
				cout<<k<<'\n';
				break;
            }
			
            q.pop();
			
			for(int i=0;i<4;i++){
				int x=fp[i](num);
				if(!visited[x]){
					visited[x]=true;
					q.push(make_pair(x,k+command[i]));
				}
			}
        }
    }
    return 0;
}
