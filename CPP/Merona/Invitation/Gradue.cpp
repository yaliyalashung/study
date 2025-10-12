#include <iostream>
using namespace std;

int main() {
	int kyo, jun, toeic;
	cin >> kyo >> jun >> toeic;

	if (kyo >= 42 && jun >= 90 && toeic >= 800) {
	
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}