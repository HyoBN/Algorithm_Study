#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    int arr_a[1000001];
    int arr_b[1000001];
    int ans[2000003];
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>arr_a[i];
    for(j=0;j<m;j++)
        cin>>arr_b[j];
    
    i=0;
    j=0;
    
    for(int k=0;k<n+m;k++){
        if(i>=n){
            ans[k]=arr_b[j++];
            continue;
        }
        else if(j>=m){
            ans[k]=arr_a[i++];
            continue;
        }
        else
            arr_a[i] > arr_b[j] ? ans[k]=arr_b[j++] : ans[k]=arr_a[i++];
    }
    for(int x=0;x<n+m;x++)
        cout<<ans[x]<<" ";
        
    return 0;
    
}