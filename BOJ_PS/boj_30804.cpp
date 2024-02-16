#include <iostream>
using namespace std;

int fruitType[10];
int tanghuru[200001];
int n,ans;

void twoPointer(int left, int right, int fruitTypeCount, int fruitCount){
    if(right>=n) return;
    if(fruitType[tanghuru[right]]==0){
        fruitTypeCount++;
    }
    fruitCount++;
    fruitType[tanghuru[right]]++;
    if(fruitTypeCount>2){
        fruitType[tanghuru[left]]--;
        if(fruitType[tanghuru[left]]==0)
            fruitTypeCount--;
        fruitCount--;
        left++;
    }
    ans = max(ans, fruitCount);
    twoPointer(left, right + 1, fruitTypeCount, fruitCount);

}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>tanghuru[i];
    }
    twoPointer(0, 0, 0, 0);

    cout<<ans;
}
