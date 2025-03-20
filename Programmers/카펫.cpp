#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    for(int x=3;x<=sqrt(brown+yellow);x++){
        if(total%x!=0) continue;
        int y = total/x;
        if(x+y == brown/2 + 2){
            answer.push_back(max(x,y));
            answer.push_back(min(x,y));
        }
    }
    
    return answer;
}
