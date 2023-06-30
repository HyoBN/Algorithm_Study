#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(i%2==0){
            maxHeap.push(tmp);
        }else{
            minHeap.push(tmp);
        }
        if(!minHeap.empty() && maxHeap.top()>minHeap.top()){
            int swap = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(swap);
        }
        printf("%d\n", maxHeap.top());
    }
}
