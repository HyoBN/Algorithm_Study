#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(!cin.eof()){
        getline(cin,str); //애초에 getline()은 공백도 입력받아짐
        cout<<str<<endl;
    }
	
	return 0;
}