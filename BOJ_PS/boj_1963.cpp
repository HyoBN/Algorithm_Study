#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

bool isPrime[10001]; 
int cnt[10001];  

void bfs(int x, int y) {
    queue<int> q;
    cnt[x] = 1;
    q.push(x);    
	
    while (!q.empty()) {
        x = q.front();
		q.pop();      
		
        if (x == y) {
			printf("%d\n",cnt[x]-1);
            return;
        }
		
        for (int i=0;i<4;i++) {            
            for (int j=0;j<10;j++) {
                if (i==0 && j==0) continue;
                string s=to_string(x);
                s[i]=j+'0';
                int nx = stoi(s);
                if (cnt[nx] || nx < 1000 || !isPrime[nx]) continue;
                cnt[nx] = cnt[x] + 1;
                q.push(nx);
            }
        }        
    }
	printf("Impossible\n");
}
 
int main() {
    int t;
	scanf("%d",&t);
	for (int i=2;i<=10000;i++)
        isPrime[i]=true;
    for (int i=2;i<=10000;i++) 
        for (int j=i;i*j<=10000;j++)
            isPrime[i*j]=false;

	for(int i=0;i<t;i++){
        int a,b;
		scanf("%d %d",&a,&b);
        memset(cnt, 0, sizeof(cnt));
        bfs(a, b);      
    }
}