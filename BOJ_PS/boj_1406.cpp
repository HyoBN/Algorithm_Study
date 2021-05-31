#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
int main(){
    int n; 
    string str; 
 
    cin >> str; 
    cin >> n;
    stack<char> s1,s2;
	for(int i=0;i<str.size();i++)
		s1.push(str[i]);

    while(n--){
        char cmd;
        cin >> cmd;
        
        if(cmd=='L'){
            if(!(s1.empty())){
                s2.push(s1.top());
                s1.pop(); 
            }
            
        } 
        else if(cmd=='D'){
            if(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(cmd=='B'){
            if(!(s1.empty())){
                s1.pop();
            }
            
        }
        else if(cmd=='P'){
            char x;
            cin >> x;
            s1.push(x);
        }    
    }
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    } 
    while(!(s2.empty())){
        cout << s2.top();
        s2.pop();
    }
    return 0;     
}