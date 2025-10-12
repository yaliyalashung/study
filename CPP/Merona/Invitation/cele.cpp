#include <iostream>
using namespace std;

int main() {

	int year = 0;
	int month = 0;
	int day = 0;
	int total = 0;
	cin >> year >> month >> day;
	/*
	if (year < 2022) {

		total += 365 * (2022 - year - 1);

		switch (month) {
		case 1:
			total += 31;
		case 2:
			total += 28;
		case 3:
			total += 31;
		case 4:
			total += 30;
		case 5:
			total += 31;
		case 6:
			total += 30;
		case 7:
			total += 31;
		case 8:
			total += 31;
		case 9:
			total += 30;
		case 10:
			total += 31;
		case 11:
			total += 30;
		case 12:
			total += 31;
		default:
			total += 0;
		}

		total += -(day - 1) + 31 + 28 + 25;
		
	}
	else {
		switch (month) {
		case 1 :
			total += 31;
		case 2:
			total += 28;
		default :
			total += (25 - (day-1));
		}
	}

	cout << total;
	*/
	/*
	if (year < 2022) {
		for (int i = month; i<=12; i++) {
			switch (i) {
			case 2:
				total += 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				total += 30;
				break;
			default:
				total += 31;
				break;
			}
		}
		total -= day;
		total++;

		total += 365 * (2022 - year - 1);
		total += 31 + 28 + 25;
	}
	else {
		for (int i = month; i < 3; i++) {
			switch (i) {
			case 2:
				total += 28;
				break;
			default:
				total += 31;
				break;
			}

		}
		total += (25 - day);
		total++;
	}
	*/

	int tempY = 2022, tempM = 3;
	total += 25;

	while (tempY != year || tempM != month) {
		if (tempM != 1) {
			tempM--;
		}
		else {
			tempY--;
			tempM = 12;
		}

		switch (tempM) {
		case 2:
			total += 28;
			break;
		case 4: case 6: case 9: case 11: total += 30; break;
		default:
			total += 31; break;
		}
	}

	total -= day - 1;
	cout << total;

	return 0;
}