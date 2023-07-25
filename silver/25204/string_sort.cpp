#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void	getWords(vector<string>& words, int size) {
	for (int i = 0; i < size; i++) {
		cin >> words[i];
	}
}

bool		compare(string& s1, string& s2) {
	string::iterator s1_it = s1.begin();
	string::iterator s2_it = s2.begin();

	while ((s1_it != s1.end()) && (s2_it != s2.end()) && (*s1_it == *s2_it)) {
		++s1_it;
		++s2_it;
	}
	if (s1_it == s1.end() && s2_it == s2.end())
		return (false);
	else if (s1_it == s1.end())
		return (true); // s1이 먼저
	else if (s2_it == s2.end())
		return (false); // s2가 먼저
	else {
		if (*s1_it == '-')
			return (false);
		else if (*s2_it == '-')
			return (true);
		else {
			if (tolower(*s1_it) == tolower(*s2_it)) {
				return ((*s1_it - *s2_it) < 0);
			}
			else
				return ((tolower(*s1_it) - tolower(*s2_it)) < 0);
		}
	}
}

void printWords(vector<string>& words)
{
	for (vector<string>::iterator it = words.begin(); it < words.end(); it++) {
		cout << *it << '\n';
	}
}

int	main(void) {
	int	test_case;

	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int	wordSize;

		cin >> wordSize;
		vector<string>	words(wordSize);
		getWords(words, wordSize);
		sort(words.begin(), words.end(), compare);
		printWords(words);
	}
}
