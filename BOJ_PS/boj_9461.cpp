#include <iostream>
using namespace std;

long long arr[101]={0,1,1,1,};

int main(){
	int t,n;
	for(int j=4;j<=101;j++)
		arr[j]=arr[j-3]+arr[j-2];
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		printf("%lld\n",arr[n]);
	}
}