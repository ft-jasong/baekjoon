#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int	dp[1001][1001];

int main(void) {
	char s1[1003] = {0, };
	char s2[1003] = {0, };

	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	for (int i = 1; i <= strlen(s1 + 1); i++) {
		for (int j = 1; j <= strlen(s2 + 1); j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
 	printf("%d\n", dp[strlen(s1 + 1)][strlen(s2 + 1)]);
	return (0);
}