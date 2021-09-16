#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];

int bi(int n, int c){
    int r=arr[n-1];
    int l=1,ans=0;
    while(l<=r){
        int cnt = 1;
        int mid = (r+l)/2;
        int start = arr[0];
        for(int i=1;i<n;i++)
            if(arr[i]-start>=mid){
				start=arr[i];
				cnt++;
			}
        if(cnt>=c){
			ans=mid;
			l=mid+1;
		}
        else r=mid-1;
    }
    return ans;
}

int main(){
    int n,c;
	scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++) 
    	scanf("%d",&arr[i]);
	
    sort(arr,arr+n);
	printf("%d",bi(n,c));
}