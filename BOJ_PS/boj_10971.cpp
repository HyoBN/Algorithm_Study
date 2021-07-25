#include<iostream>
using namespace std;

int arr[11][11]; 
int check[11]; 
int n;         
int m = 999999999; 
void dfs(int start, int y, int sum, int cnt){
    if(cnt == n && start == y){
        if(m > sum) m = sum;
        return;
    }
 
    for(int x=0; x<n; x++){
        if(arr[y][x] == 0) continue;    
        if(!check[y] && arr[y][x] >0) {
            check[y] = true;    
            sum+=arr[y][x];
 
            if(sum <= m)  
                dfs(start, x, sum, cnt+1);
            check[y] = false;
            sum-=arr[y][x];
        }
    }
}
 
 
int main(void){

	
    scanf("%d", &n);
	
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
	
    dfs(0, 0, 0, 0);
    
    printf("%d", m);
    return 0;
}

