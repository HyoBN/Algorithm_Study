#include <iostream>
using namespace std;
 

long long gcd(long long a, long long b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

long long solution(int w,int h) {
    long long lw = w;
    long long lh = h;
    long long answer = 1;
    long long gcdNum;
    if(lw<lh) gcdNum=gcd(lh,lw);
    else gcdNum=gcd(lw,lh);
    answer = lw*lh-(lw+lh-gcdNum);
    
    return answer;
}
