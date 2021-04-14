#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;


bool compare(const  pair<pair<string, int>,pair<int,int>> &a,  pair<pair<string, int>,pair<int,int>> &b)
{
    if(a.first.second==b.first.second)
    {
        if(a.second.first==b.second.first)
        {
            if(a.second.second==b.second.second)
            {
                return a.first.first < b.first.first;
            }
            return a.second.second > b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first.second > b.first.second;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;    
    
    pair<pair<string, int>,pair<int,int>> arr[100001];
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;

    sort(arr,arr+n,compare);
    
    for(int i=0;i<n;i++)
        cout<<arr[i].first.first<<"\n";
    

}
