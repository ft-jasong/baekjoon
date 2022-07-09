#include <iostream>
#include <string>

void	get_broken_list(std::string &list)
{
	int			broken_size;
	std::string	buffer;

	std::cin >> broken_size;
	for (int b = 0; b < broken_size; b++)
	{	
		std::cin >> buffer;
		list += buffer;
	}
}

int	ispossible(int n, std::string blist)
{
	std::string	s_num;

	s_num = std::to_string(n);
	for (std::string::iterator iter = s_num.begin(); iter != s_num.end(); ++iter)
	{
		if (blist.find(*iter) != std::string::npos)
			return (0);
	}
	return (1);
}

int	num_press(int channel, std::string blist)
{
	int	n;
	int	ret;
	int	tmp;
	int	up_num;
	int	down_num;

	up_num = channel;
	down_num = channel;
	ret = 987654321;
	while (!ispossible(up_num, blist) && up_num <= 1000000)
		up_num++;
	while (!ispossible(down_num, blist) && down_num >= 0)
		down_num--;
	if (down_num < 0)
		down_num = 987654321;
	if (up_num > 1000000)
		up_num = 987654321;
	if (abs(up_num - channel) + std::to_string(up_num).length() > abs(down_num - channel) + std::to_string(down_num).length())
		return (abs(down_num - channel) + std::to_string(down_num).length());
	return (abs(up_num - channel) + std::to_string(up_num).length());
}

int	main(void)
{
	int			ch;
	std::string	broken_list;
	int			no_num;
	int			channel_move;

	std::cin >> ch;
	get_broken_list(broken_list);
	no_num = abs(ch - 100);
	channel_move = num_press(ch, broken_list);
	if (channel_move < no_num)
		std::cout << channel_move << std::endl;
	else
		std::cout << no_num << std::endl;
}