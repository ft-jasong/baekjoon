#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double months[12];
	double sum = 0;

	for(int i = 0; i < 12; i++) {
		cin >> months[i];
		sum += months[i];
	}

	double average = sum / 12;
	double test = 141.4149999999;

	cout << fixed << setprecision(2);
	cout << "$" << average << endl;
	return 0;
}