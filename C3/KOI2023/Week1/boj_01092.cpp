#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m,ans=0;
    int cranePointer,boxCnt=0;
    int crane[51],box[10001];
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> crane[i];
    }
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin >> box[i];
    }

    sort(crane, crane + n);
    sort(box,box+m);

    // 모든 박스를 배로 옮길 수 없는 경우(가장 무거운 박스 무게> 크레인 무게 제한 최대)
    if(crane[n - 1] < box[m - 1]){
        cout<<-1;
        return 0;
    }
    
    while(boxCnt<m){
        ans++;
        cranePointer= n - 1;
        for(int i=m-1;i>=0;i--){
            if(box[i]==0) continue;
            if(cranePointer <= -1) break;
            if (box[i] <= crane[cranePointer]) {
                cranePointer--;
                boxCnt++;
                box[i]=0;
            }
        }
    }
    cout<<ans;
}
