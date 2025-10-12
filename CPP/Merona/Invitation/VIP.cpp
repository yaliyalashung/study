#include <iostream>
using namespace std;

int main() {
	int number = 0;
	int price[10000] = { 0, };
	int total = 0;
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> price[i];
		total += price[i];
	}
	cout << total;
	return 0;
}