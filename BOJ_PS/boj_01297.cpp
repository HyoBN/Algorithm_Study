#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int d,h,w;
	double x;
	cin>>d>>h>>w;
	
	x=sqrt(pow(d,2)/(pow(h,2)+pow(w,2)));
	cout<<(int)(h*x)<<' '<<(int)(w*x);
	
}