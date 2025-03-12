#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    
    return a+b > b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numStr;
    bool allZeroCheck=true;
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]!=0) allZeroCheck=false;
        numStr.push_back(to_string(numbers[i]));
    }
    
    if(allZeroCheck) return "0";
    
    sort(numStr.begin(),numStr.end(),cmp);
    for(int i=0;i<numStr.size();i++){
        answer+=numStr[i];
    }
    
    return answer;
}
