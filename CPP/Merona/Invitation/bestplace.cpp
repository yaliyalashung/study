#include <iostream>
using namespace std;

int main() {
	
	char place[6][10] = { {0,}, };
	int bestplace = 0;
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> place[i][j];
			if (i>0 && place[i - 1][j] == '^' && place[i][j] == '~') bestplace++;
		}
	}


	cout << bestplace;

	return 0;
}