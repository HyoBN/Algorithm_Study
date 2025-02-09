#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000001];
int lis[1000001];
int lisIdx=0;

int getLisUpdateIdx(int value){
    int start=0;
    int end = lisIdx;

    while(start<=end){
        int mid = (start+end)/2;
        if(lis[mid]>=value){
            end = mid-1;
        }
        else start = mid+1;
    }
    return start;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    lis[0]=arr[0];

    for (int i = 1; i < n; i++) {
        if(arr[i]>lis[lisIdx]){
            lisIdx++;
            lis[lisIdx] = arr[i];
        }
        else{
            int tmpIdx = getLisUpdateIdx(arr[i]);
            lis[tmpIdx] = arr[i];
        }
    }
    cout<<lisIdx+1;

}
