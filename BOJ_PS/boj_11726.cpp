#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[1001] = {1,1,};
    scanf("%d",&n);
    
    for(int i=2;i<=n;i++)
        arr[i] = (arr[i-2] + arr[i-1])%10007;
    
    printf("%d",arr[n]);
}
