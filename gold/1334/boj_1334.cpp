#include <iostream>
#include <string>

using namespace std;

void printNextPelindrome(string& input) {
	int carry;

	carry = 0;
	if (input.size() % 2 == 0) {
		input[(input.size() - 1) / 2]++;
		for (int i = (input.size() - 1) / 2; i >= 0; i--) {
			if (input[i] + carry > '9') {
				carry = 1;
				input[i] = '0';
			}
			else
				carry = 0;
			input[input.size() - 1 - i] = input[i];
		}
		if (carry) {
			cout << '1';
			input[input.size() - 1] = '1';
		}
		cout << input << '\n';
	}
	else {
		input[input.size() / 2]++;
		for (int i = input.size() / 2; i >= 0; i--) {
			if (input[i] + carry > '9') {
				carry = 1;
				input[i] = '0';
			}
			else
				carry = 0;
			input[input.size() - 1 - i] = input[i];
		}
		if (carry) {
			cout << 1;
			for (int i = 0; i < input.size() - 1; i++)
				cout << 0;
			cout << 1 << '\n';
		}
		else
			cout << input << '\n';
	}
}

 int main(void) {
	 string input;

	 cin >> input;
	 printNextPelindrome(input);
	 return (0);
}

