#include <iostream>

int	main(void)
{
	int	s_w, s_h, g_w, g_h;
	int	max_w, max_h;

	std::cin >> s_w >> s_h >> g_w >> g_h;
	max_w = 0;
	while (s_w >= g_w * (2 * max_w + 1))
		max_w++;
	while (s_h >= g_h * (2 * max_h + 1))
		max_h++;
	std::cout << max_w * max_h << std::endl;
}