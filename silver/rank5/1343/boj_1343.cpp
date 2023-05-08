#include <iostream>
#include <string>

using namespace std;

int	main(void) {
	string	inpt;

	cin >> inpt;
	while (true) {
		int	pos = inpt.find("XXXX");
		if (pos == string::npos)
			break ;
		inpt.replace(pos, 4, "AAAA");
	}
	while (true) {
		int	pos = inpt.find("XX");
		if (pos == string::npos)
			break ;
		inpt.replace(pos, 2, "BB");
	}
	if (inpt.find("X") != string::npos)
		cout << -1 << endl;
	else
		cout << inpt << endl;
	return (0);
}
