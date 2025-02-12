#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v;
int countZero=0,countOne=0;

void quadFunction(int startX, int startY, int size){
    if(size==0) return;
    int value = v[startY][startX];
    bool sameFlag=true;
    bool exitFlag=false;
    for(int i=startY;i<startY+size;i++){
        if(exitFlag) break;
        for(int j=startX;j<startX+size;j++){
            if(v[i][j]!=value){
                sameFlag=false;
                exitFlag=true;
                break;
            }
        }
    }
    if(sameFlag){
        value==0 ? countZero++ : countOne++;
    }
    else{
        quadFunction(startX, startY, size/2);
        quadFunction(startX+size/2, startY, size/2);
        quadFunction(startX, startY+size/2, size/2);
        quadFunction(startX+size/2, startY+size/2, size/2);

    }
}

vector<int> solution(vector<vector<int>> arr) {
    v=arr;
    vector<int> answer;
    quadFunction(0, 0, v[0].size());
    answer.push_back(countZero);
    answer.push_back(countOne);
    return answer;
}
