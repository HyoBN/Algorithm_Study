#include <iostream>
using namespace std;

int main()
{
	int screen_length;
	int bucket_length;
	int apple_count;
	int apple_location[21];
	int bucket_right_location;
	
	int move_count=0;
	
	cin>>screen_length>>bucket_length;
	cin>>apple_count;
	bucket_right_location=bucket_length;
	
	for(int i=1;i<=apple_count;i++)
		cin>>apple_location[i];
	
	for(int i=1;i<=apple_count;i++)
	{
		if(apple_location[i]>bucket_right_location)
		{
			move_count+=apple_location[i]-bucket_right_location;
			bucket_right_location=apple_location[i];
			continue;
		}
		else if(apple_location[i]<bucket_right_location-bucket_length+1)
		{
			move_count+=bucket_right_location-bucket_length+1-apple_location[i];
			bucket_right_location=apple_location[i]+bucket_length-1;
		}
	}
	cout<<move_count;
	 
	
}