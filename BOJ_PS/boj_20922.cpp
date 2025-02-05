#include <iostream>
using namespace std;

int check[200001];
int arr[200001];
int n,k;
int nowLen,ans;
int startIdx, endIdx;

int main(){
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        check[arr[i]]++;
        if(check[arr[i]]<=k){
            endIdx=i;
            nowLen++;
        }
        else{
            while(arr[startIdx]!=arr[i]){
                check[arr[startIdx]]--;
                startIdx++;
            }
            nowLen=endIdx-startIdx+1;
        }
        ans=max(nowLen,ans);
    }
    cout<<ans;


}
