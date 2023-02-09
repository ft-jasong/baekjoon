#include <iostream>
#include <cmath>

int	main(void)
{
	int x1, x2;
	int y1, y2;
	int r1, r2;
	int answer;
	int test_case;

	std::cin >> test_case;
	while (test_case--)
	{
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if ((x1 == x2) && (y1 == y2))
		{
			if (r1 == r2)
				std::cout << -1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		else
		{
			if ((int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) == (int)pow(r1 + r2, 2) || (int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) == (int)pow(r1 - r2, 2))
				std::cout << 1 << std::endl;
			else if ((int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) > (int)pow(r1 - r2, 2) && (int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) < (int)pow(r1 + r2, 2))
				std::cout << 2 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
	}
	return (0);
}