#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int arr[12]={0,1,2,4,};
    for(int i=4;i<=11;i++)
        arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }
}