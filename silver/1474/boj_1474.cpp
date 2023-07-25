#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int	main(void) {
	int				N;
	int				M;
	string			tmp;
	int				words_len;
	vector<string>	v_str;
	int				div;
	int				rem;

	cin >> N >> M;
	v_str.reserve(N);
	words_len = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v_str.push_back(tmp);
		words_len += tmp.length();
	}
	div = (M - words_len) / (N - 1);
	rem = (M - words_len) % (N - 1);
	cout << v_str[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < div; j++)
			cout << '_';
		if (rem > 0 && (islower(v_str[i][0]) || (rem == N - i))) {
			cout << '_';
			rem--;
		}
		cout << v_str[i];
	}
	cout << '\n';
	return (0);
}