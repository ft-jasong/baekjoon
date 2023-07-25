#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<char, int> a1, pair<char, int> a2) {
	return (a1.first < a2.first);
}

int main(void) {
	string	key;
	char	ciphertext[101] = {0, };
	char	aligned_c[101] = {0, };
	char	plaintext[101] = {0, };
	vector<pair<char, int> >	v_order;
	int		idx;

	cin >> key;
	cin >> ciphertext;
	idx = 0;
	for (auto it = key.begin(); it < key.end(); it++) {
		v_order.push_back(make_pair(*it, idx++));
	}
	idx = 0;
	stable_sort(v_order.begin(), v_order.end(), comp);
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < strlen(ciphertext) / key.size(); j++) {
			aligned_c[key.size() * j + i] = ciphertext[idx++];
		}
	}
	idx = 0;
	for (auto it = v_order.begin(); it < v_order.end(); it++) {
		int offset = it->second;
		for (int i = 0; i < strlen(aligned_c) / key.size(); i++) {
			plaintext[i * key.size() + offset] = aligned_c[i * key.size() + idx];
		}
		idx++;
	}
	cout << plaintext << endl;
	return (0);
}