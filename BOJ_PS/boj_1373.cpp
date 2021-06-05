#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
 
using namespace std;
 
int main() {
    string s = "";
    getline(cin, s);
	
    while (s.size() % 3 != 0) //3자리씩 묶을 수 있도록 왼쪽에 0붙임.
        s = '0' + s;
	
    string ans = "";
	
    for (int i = 0; i < s.size(); i+=3) { //세 자리씩 건너뜀.
        int tmp = 0;
        for (int j = i; j < i+3; j++) 
            tmp += (s[j]-'0')*pow(2,2-(j%3));
        
        ans += to_string(tmp);
    }
    for (int i = 0; i < ans.size(); i++)
		cout<<ans[i];
}
