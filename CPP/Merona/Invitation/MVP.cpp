#include <iostream>
using namespace std;

int main() {

	int N = 0;
	int array[100] = { 0, };
	int stack[100] = { 0, };
	int bestscore = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> array[i];
		stack[i] = array[i];
		if (i > 0) stack[i] += stack[i - 1];
		if (i >= 4) {  
			int currentSum = (i >= 5) ? (stack[i] - stack[i - 5]) : stack[i];
			bestscore = currentSum > bestscore ? currentSum : bestscore;
		}
	}

	cout << bestscore;
	return 0;
}