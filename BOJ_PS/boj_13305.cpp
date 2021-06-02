#include <iostream>
using namespace std;

int main() {
	
	int n;
	long long distance[100001];
	long long city_oil_price[100001];
	
	long long total_money = 0; 
	
	cin>>n;
	
	for(int i = 0; i < n - 1; i++)
		cin >> distance[i];
	for(int i = 0; i < n; i++)
		cin >> city_oil_price[i]; 
	
	long long cheap_oil = city_oil_price[0];

	
	for(int i = 0; i < n - 1; i++)
	{
		if(city_oil_price[i] < cheap_oil)
			cheap_oil = city_oil_price[i];
		total_money += distance[i] * cheap_oil;
	}
	cout << total_money;
}
