#include <iostream>

int	main(void) {
	int	age;
	int	split_factor;
	int	cutted;

	while (true) {
		std::cin >> age;
		if (!age)
			break ;
		int	ret = 1;
		for (int i = 0; i < age; i++) {
			std::cin >> split_factor >> cutted;
			ret = ret * split_factor - cutted;
		}
		std::cout << ret << std::endl;
	}
}