#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int binaryCount, zeroCount;

string deleteZero(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            zeroCount++;
        }else{
            result+=s[i];
        }
    }
    return result;
}

string intToBinary(int num){
    string s;
    while(num>1){
        s+=num%2+'0';
        num/=2;
        if(num==1){
            s+='1';
            break;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

void func(string input){

    while(input!="1") {
        binaryCount++;
        input = deleteZero(input);
        input = intToBinary(input.length());
        if(input=="") break;
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    func(s);
    answer.push_back(binaryCount);
    answer.push_back(zeroCount);
    return answer;
}
