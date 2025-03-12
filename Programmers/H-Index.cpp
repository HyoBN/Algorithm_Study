#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    sort(citations.begin(),citations.end());
    int maxH=0;
    for(int i=0;i<n;i++){
        maxH = max(maxH,citations[i]);
    }
    
    for(int h=0;h<maxH;h++){
        for(int i=0;i<n;i++){
            if(citations[i]>=h){
                if(n-i>=h){
                    answer =h;
                }
            } 
        }
    }
    
    
    return answer;
}
