#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<< (((n/3 + n%3) %2==0) ? "CY" : "SK");
}
