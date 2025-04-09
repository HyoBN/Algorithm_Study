#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i=1;i<=r2;i++){
        double y2 = sqrt(pow(r2,2) - pow(i,2));
        double y1 = sqrt(pow(r1,2) - pow(i,2));
        answer += ((long long)y2 - (long long)ceil(y1) +1);
    }
       
    return answer*4;
}
