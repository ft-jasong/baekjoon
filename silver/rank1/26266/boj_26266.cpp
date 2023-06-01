#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	char	plainText[200001] = {0, };
	char	cipherText[200001] = {0, };
	char	key[200001] = {0, };
	int		textLen;
	int		idx;

	cin >> plainText;
	cin >> cipherText;
	idx = 0;
	while (plainText[idx]) {
		key[idx] = (cipherText[idx] - plainText[idx] + 26) % 26;
		idx++;
	}
	textLen = strlen(plainText);
	for (int i = 1; i < textLen; i++) {
		if (textLen % i == 0) {
			for (idx = 0; idx < textLen - i; idx++) {
				if (key[idx] != key[idx + i])
					break;
			}
			if (idx == textLen - i) {
				for (int j = 0; j < i; j++)
					cout << (char)(('A' + (key[j] + 25) % 26) );
				cout << endl;
				return (0);
			}
		}
	}
	for (int i = 0; i < textLen; i++) {
		cout << (char)('A' + (key[i] + 25) % 26);
	}
	cout << endl;
	return (0);
}