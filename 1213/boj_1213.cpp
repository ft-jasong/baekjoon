#include <iostream>
#include <string>
#include <map>

using namespace std;

int	main(void)
{
	map<char, int>	mp;
	string			input;
	int				odd_sum;
	char			odd_char;

	cin >> input;
	for (string::iterator it = input.begin(); it < input.end(); it++)
	{
		if (mp.find(*it) == mp.end())
			mp[*it] = 1;
		else
			mp[*it] += 1;
	}
	odd_sum = 0;
	odd_char = 0;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second % 2 == 1)
		{
			++odd_sum;
			odd_char = it->first;
			if (odd_sum > 1)
			{
				cout << "I'm Sorry Hansoo\n";
				return (0);
			}
		}
	}
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		for (int i = 0; i < it->second / 2; i++)
			cout << it->first;
	}
	if (odd_sum == 1)
		cout << odd_char;
	for (map<char, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
	{
		for (int i = 0; i < it->second / 2; i++)
			cout << it->first;
	}
	cout << '\n';
	return (0);
}