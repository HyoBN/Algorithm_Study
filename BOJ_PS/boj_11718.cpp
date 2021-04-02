#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(!cin.eof()){
        getline(cin,str);
        cout<<str<<endl;
    }
	
	return 0;
}