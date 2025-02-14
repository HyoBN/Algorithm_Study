#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string str;

bool isCorrectString(){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='[' || str[i]== '{' || st.empty()){
            st.push(str[i]);
        }
        else{
            char tmp = st.top();
            st.pop();
            if((str[i]==')' && tmp=='(') || (str[i]==']' && tmp=='[') ||
               (str[i]=='}' && tmp=='{')){
                continue;
            }
            else return false;
        }
    }
    if(st.empty())
        return true;
    else return false;
}

void lotate(){
    string res = str.substr(1);
    res+=str[0];
    str=res;
    // return res;
}

int solution(string s) {
    int answer = 0;
    str=s;
    for(int i=0;i<str.length();i++){
        if(isCorrectString())
            answer++;
        lotate();
    }
    
    return answer;
}
