#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	string						name;
	int							noListen;
	int							noSeen;
	int							i;
	unordered_map<string, int>	mp;
	map<string, string>			answer;


	cin >> noListen >> noSeen;
	i = -1;
	while (++i < noListen + noSeen)
	{
		cin >> name;
		if (mp.find(name) == mp.end())
			mp[name] = 1;
		else
		{
			mp[name] += 1;
			answer[name] = name;
		}
	}
	cout << answer.size() << '\n';
	for (map<string, string>::iterator it = answer.begin(); it != answer.end(); it++)
		cout << it->first << '\n';
	return (0);
}
