#include <string>
#include <cstring>
#include <vector>

using namespace std;

int popsBallonCount=0;
int minIdx=0;
vector<int> v;
int minArr[1000001];

void func(){
    int len=v.size();
    minArr[0]=v[0];
    minArr[len-1]=v[len-1];
    
    for(int i=1;i<len;i++){
        if(v[minIdx]>v[i]) minIdx=i;
    }
    
    for(int i=1;i<minIdx;i++){
        if(v[i]>minArr[i-1]){
            popsBallonCount++;
        }
        minArr[i]=min(minArr[i-1],v[i]);
    }
    
    for(int i=len-2;i>minIdx;i--){
        if(v[i]>minArr[i+1]){
            popsBallonCount++;
        }
        minArr[i]=min(minArr[i+1],v[i]);
    }
    
}

int solution(vector<int> a) {
    v=a;
    int answer = 0;
    func();
    answer = a.size()-popsBallonCount;
    return answer;
}


