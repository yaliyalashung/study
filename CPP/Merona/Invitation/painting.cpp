#include <iostream>
using namespace std;

int main() {
	int N;
	char painting[1001];

	cin >> N >> painting;

	for (int i = 0; i < N; i++) {
		if (painting[i] == 'C') cout << i;
	}
	return 0;
}