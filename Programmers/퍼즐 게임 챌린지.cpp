#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> diffV;
vector<int> timeV;
long long limitTime;

bool getProcessTime(int level){
    long long processTime;
    int timePrev=timeV[0];
    processTime = timeV[0];
    
    for(int i=1;i<diffV.size();i++){
        if(diffV[i]<=level){
            processTime +=timeV[i];
        }else{
            processTime += (timeV[i]+timePrev) * (diffV[i]-level) + timeV[i];
        }
        timePrev = timeV[i];
        
        if(processTime>limitTime){
            return false;
        }
    }
    return true;
    
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    diffV = diffs;
    timeV = times;
    limitTime = limit;
    
    int answer = 1;
    
    int left=1,right=1;
    for(int i=0;i<diffV.size();i++){
        right = max(right,diffV[i]);
    }
    
    while(left<right){
        
        int mid = (left+right)/2;
        if(!getProcessTime(mid)){
            left=mid+1;
        } else{
            right=mid;
        }
        answer=left;
    }
    
    
    return answer;
}
