#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	map[26][26];

int	main(void) {
	int		n, m;
	char	s, e;
	string	is;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> is >> e;
		map[s - 'a'][e - 'a'] = 1;
	}
	for (int row = 0; row < 26; row++) {
		for (int col = 0; col < 26; col++) {
			if (!map[row][col] && row != col)
				map[row][col] = 987654321;
		}
	}
	for (int k = 0; k < 26; k++) {
		for (int j = 0; j < 26; j++) {
			for (int i = 0; i < 26; i++) {
				if (map[j][i] > (map[j][k] + map[k][i]))
					map[j][i] = map[j][k] + map[k][i];
			}
		}
	}
	cin >> m; 
	for (int i = 0; i < m; i++) {
		cin >> s >> is >> e;
		if (map[s - 'a'][e - 'a'] < 987654321)
			cout << 'T' << endl;
		else
			cout << 'F' << endl;
	}
}