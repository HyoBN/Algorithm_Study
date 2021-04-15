#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];    

int main()
{
    
    int n;
    int max_cnt=0;
    int now_cnt=1;
    int index=0;
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1]){
            now_cnt++;
            if(now_cnt>max_cnt){
                max_cnt=now_cnt;
                index=i;
            }
        }
        else now_cnt=1;
        
    }
    
    cout<<arr[index];
    
}