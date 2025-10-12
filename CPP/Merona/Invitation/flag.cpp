#include <iostream>
using namespace std;

int main() {
	char flag;
	char ud;

	cin >> flag >> ud;

	flag == 'B' ? cout << "Blue Flag " : cout << "White Flag ";
	ud == 'U' ? cout << "Up!" << endl : cout << "Down!" << endl;

	return 0;
}