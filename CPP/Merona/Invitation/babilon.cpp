#include <iostream>
using namespace std;

int main() {
	int N;
	float X = 1.0;
	float Y = 1.0;
	cin >> N;

	for (int i = 0; i < 20; i++) {
		Y = (float)N / X;
		X = (X + Y) / 2;
	}
	cout << (int)X;
	return 0;
}