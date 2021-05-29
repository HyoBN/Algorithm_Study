#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int arr[200002];
	int push_num;
	
	int front_pointer=100000;
	int rear_pointer=100001;
	string command;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>command;
		
		if(command=="push_front"){
			cin>>push_num;
			arr[front_pointer--]=push_num;
			
		}
		else if(command=="push_back"){
			cin>>push_num;
			arr[rear_pointer++]=push_num;
		}
		else if(command=="pop_front"){
			if(rear_pointer-front_pointer==1)
				cout<<-1<<endl;
			else cout<<arr[++front_pointer]<<endl;
		}
		else if(command=="pop_back"){
			if(rear_pointer-front_pointer==1)
				cout<<-1<<endl;
			else cout<<arr[--rear_pointer]<<endl;
		}
		else if(command=="size")
			cout<<rear_pointer-front_pointer-1<<endl;
		else if(command=="empty")
			cout<<(rear_pointer-front_pointer==1 ? 1:0)<<endl;
		else if(command=="front"){
			if(rear_pointer-front_pointer==1)
				cout<<-1<<endl;
			else cout<<arr[front_pointer+1]<<endl;
		}
		else if(command=="back"){
			if(rear_pointer-front_pointer==1)
				cout<<-1<<endl;
			else cout<<arr[rear_pointer-1]<<endl;
		}
		
	}
	return 0;
}