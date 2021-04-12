#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int arr[1000001];
    int temp;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
                
}
