#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		string s = to_string(i);
		if (s.size() <= 2)
			++answer;
		else
		{
			int diff = s[1] - s[0];
			bool flag = true;
			for (int j = 2; j < (int)s.size(); j++)
			{
				if (s[j] - s[j - 1] != diff)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				++answer;
		}
	}
	cout << answer << endl;
}