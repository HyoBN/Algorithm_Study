#include<iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int stack[100001];
	int top_pointer=-1;
	int num;
	string command;
		
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>command;
		if(command=="push")
		{
			cin>>num;
			stack[++top_pointer]=num;
		}
		else if(command=="pop")
		{
			if(top_pointer==-1) cout<<-1<<endl;
			else cout<<stack[top_pointer--]<<endl;
		}
		else if(command=="size")
			cout<<top_pointer+1<<endl;
		else if(command=="empty")
			cout<< (top_pointer==-1 ? 1 : 0)<<endl;
		else if(command=="top")
		{
			if(top_pointer==-1) cout<<-1<<endl;
			else cout<<stack[top_pointer]<<endl;
		}
		
	}
	return 0;
	
}