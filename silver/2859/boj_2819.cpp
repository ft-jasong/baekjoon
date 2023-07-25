#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int		hour;
	int		min;
	int		initMin1;
	int		initMin2;
	int		adder1;
	int		adder2;
	int		time1;
	int		time2;
	char	dayOfWeek[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	char	colon;

	cin >> hour >> colon >> min;
	initMin1 = hour * 60 + min;
	cin >> hour >> colon >> min;
	initMin2 = hour * 60 + min;
	cin >> hour >> colon >> min;
	adder1 = hour * 60 + min;
	cin >> hour >> colon >> min;
	adder2 = hour * 60 + min;
	time1 = initMin1;
	time2 = initMin2;
	do {
		while (time2 < time1) {
			time2 += adder2;
		}
		if (time1 == time2) {
			cout << dayOfWeek[(time1 / 1440) % 7] << '\n';
			cout << setw(2) << setfill('0') << to_string((time1 / 60) % 24);
			cout << ':';
			cout << setw(2) << setfill('0') << to_string(time1 % 60) << '\n';
			return (0);
		}
		time1 += adder1;
	} while (time1 % 10040 != initMin1);
	cout << "Never\n";
}