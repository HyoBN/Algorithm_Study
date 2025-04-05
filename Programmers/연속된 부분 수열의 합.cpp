#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start=0,end=0;
    pair<int,int> range = {0,sequence.size()};
    int nowSum=sequence[0];
    
    while(true){
        if(end>=sequence.size()) break;
        
        if(nowSum==k){
            if(end-start < range.second-range.first){
                range={start,end};
                cout<<"HI!!"<<endl;
            }
            else nowSum+=sequence[++end];
        }
        else if(nowSum < k){
            nowSum+=sequence[++end];
        }
        else{
            nowSum-=sequence[start];
            start++;
        }
    }
    
    answer.push_back(range.first);
    answer.push_back(range.second);
    
    return answer;
}
