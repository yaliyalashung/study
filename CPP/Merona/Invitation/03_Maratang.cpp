#include <iostream>
using namespace std;

int main() {


	double gram;
	cin >> gram;

	cout << (int)((double)2000 + gram / 100 * 1730) /100 * 100;


	return 0;
}