#include <iostream>
#include <string>

using namespace std;

bool	deleteDuck(string& sound) {
	string duck = "quack";
	int	i;
	bool find;
	int repl_idx[5] = {0, };
	int quack_idx;

	find = false;
	quack_idx = 0;
	for (int i = 0; i < sound.size(); i++) {
		if (sound[i] == duck[quack_idx]) {
			repl_idx[quack_idx] = i;
			quack_idx++;
		}
		if (quack_idx == 5) {
			for (int j = 0; j < quack_idx; j++)
				sound[repl_idx[j]] = '_';
			quack_idx = 0;
			find = true;
		}
	}
	return (find);
}

int main(void) {
	string	sound;
	bool	isCorrect;
	int		ans;

	cin >> sound;
	ans = 0;
	while (deleteDuck(sound)) {
		ans++;
	}
	isCorrect = true;
	for (int i = 0; i < sound.size(); i++) {
		if (sound[i] != '_')
			isCorrect = false;
	}
	if (!isCorrect)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return (0);
}