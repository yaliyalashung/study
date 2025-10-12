#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	float food_cost;
	food_cost = (float)(a * 50 + b * 10 + c * 20) / 100;
	cout << food_cost;

	return 0;
}