#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> makeCandidate(const vector<string>& v_str, int size, int len) {
	vector<string>	ret;
	string	tmp;

	ret.reserve(26 * size * len);
	for (int i = 0; i < size; i++) {
		for (int l = 0; l < len; l++) {
			tmp = v_str[i];
			for (char c = 'A'; c <= 'Z'; c++) {
				tmp[l] = c;
				ret.push_back(tmp);
			}
		}
	}
	return (ret);
}

int	checkMaxdiff(const string& str1, const string& str2) {
	int	ret;

	ret = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i])
			ret++;
	}
	return (ret);
}

int	main(void) {
	int	size;
	int	len;
	vector<string>	v;
	vector<string>	candidate;

	cin >> size >> len;
	v.resize(size);
	for (int i = 0; i < size; i++)
		cin >> v[i];
	candidate = makeCandidate(v, size, len);
	for (int i = 0; i < candidate.size(); i++) {
		bool pass = true;
		for (int j = 0; j < size; j++) {
			if (checkMaxdiff(candidate[i], v[j]) > 1) {
				pass = false;
				break ;
			}
		}
		if (pass) {
			cout << candidate[i] << endl;
			return (0);
		}
	}
	cout << "CALL FRIEND\n";
	return (0);
}