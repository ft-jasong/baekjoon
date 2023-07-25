#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int	getAns(unordered_map<string, string>& ump,
			vector<string>& names,
			unordered_map<string, int>& visited)
{
	int	ans;
	string	next;

	ans = 0;
	for (int i = 0; i < names.size(); i++) {
		if (!visited[names[i]]) {
			next = names[i];
			while (!visited[next]) {
				visited[next] = 1;
				next = ump[next];
			}
			ans++;
		}
	}
	return (ans);
}

int main(void) {
	int	num;
	string	src;
	string	dest;
	unordered_map<string, string>	ump;
	unordered_map<string, int>	visited;
	vector<string>	names;
	int	test_num;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test_num = 1;
	while (true) {
		cin >> num;
		if (!num)
			break ;
		names.clear();
		ump.clear();
		names.reserve(num);
		for (int i = 0; i < num; i++) {
			cin >> src >> dest;

			ump[src] = dest;
			names.push_back(src);
			visited[src] = 0;
		}
		cout << test_num << ' ' << getAns(ump, names, visited) << '\n';
		test_num++;
	}
	return (0);
}