#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int nowLocation= targets[0][1];
    for(int i=0;i<targets.size();i++){
        if(targets[i][0]>=nowLocation){
            nowLocation = targets[i][1];
            answer++;
        }
    }
    
    
    
    return answer;
}

