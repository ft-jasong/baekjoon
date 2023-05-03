// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int>				Pos;
typedef vector<pair<int, int> >		PosVector;
typedef vector<pair<int, char> >	DirVector;

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

void	getApple(int appleNum, PosVector& applePos) {
	int	row;
	int	col;

	while (appleNum--) {
		cin >> row >> col;
		applePos.push_back(make_pair(row, col));
	}
}

void getDirinfo(int dirSize, DirVector& dirInfo) {
	int		time;
	char	command;

	while (dirSize--) {
		cin >> time >> command;
		dirInfo.push_back(make_pair(time, command));
	}
}

int	isApplePos(Pos nextPos, PosVector& applePos) {
	for (int i = 0; i < applePos.size(); i++) {
		if (nextPos == applePos[i]) {
			// cout << "apple in (" << nextPos.first << ", " << nextPos.second << ")" << endl;
			return (i);
		}
	}
	return (-1);
}

bool	isBody(PosVector& snakeQueue, Pos nextPos) {
	for (PosVector::iterator it = snakeQueue.begin(); it < snakeQueue.end(); it++) {
		if (*it == nextPos)
			return (true);
	}
	return (false);
}

bool	move(PosVector& snakeQueue, PosVector& applePos, int boardSize, int dir) {
	Pos	nextPos;
	int	appleIdx;

	if (dir == UP)
		nextPos = make_pair(snakeQueue.front().first - 1, snakeQueue.front().second);
	if (dir == DOWN)
		nextPos = make_pair(snakeQueue.front().first + 1, snakeQueue.front().second);
	if (dir == LEFT)
		nextPos = make_pair(snakeQueue.front().first, snakeQueue.front().second - 1);
	if (dir == RIGHT)
		nextPos = make_pair(snakeQueue.front().first, snakeQueue.front().second + 1);
	if (nextPos.first <= 0 || nextPos.first > boardSize
		|| nextPos.second <= 0 || nextPos.second > boardSize)
		return (false);
	if (isBody(snakeQueue, nextPos))
		return (false);
	appleIdx = isApplePos(nextPos, applePos);
	if (appleIdx == -1)
		snakeQueue.pop_back();
	else
		applePos.erase(applePos.begin() + appleIdx);
	snakeQueue.insert(snakeQueue.begin(), nextPos);
	return (true);
}

int	changeDir(int curDir, char command) {
	if (curDir == UP && command == 'D')
		return (RIGHT);
	if (curDir == UP && command == 'L')
		return (LEFT);
	if (curDir == DOWN && command == 'D')
		return (LEFT);
	if (curDir == DOWN && command == 'L')
		return (RIGHT);
	if (curDir == LEFT && command == 'D')
		return (UP);
	if (curDir == LEFT && command == 'L')
		return (DOWN);
	if (curDir == RIGHT && command == 'D')
		return (DOWN);
	if (curDir == RIGHT && command == 'L')
		return (UP);
	return (-1);
}

int	playGame(PosVector& snakeQueue, PosVector& applePos, DirVector& dirInfo, int boardSize) {
	int	dir;
	int	time;

	dir = RIGHT;
	time = 0;
	while (true) {
		if (time && time == dirInfo.front().first) {
			dir = changeDir(dir, dirInfo.front().second);
			dirInfo.erase(dirInfo.begin());
		}
		++time;
		// cout << "\ntime: " <<  time << endl;
		if (!move(snakeQueue, applePos, boardSize, dir))
			break ;
	}
	return (time);
}

int	main(void) {
	int			boardSize;
	int			appleNum;
	int			dirSize;
	PosVector	snakeQueue;
	PosVector	applePos;
	DirVector	dirInfo;

	cin >> boardSize;
	cin >> appleNum;
	getApple(appleNum, applePos);
	cin >> dirSize;
	getDirinfo(dirSize, dirInfo);
	snakeQueue.push_back(make_pair(1, 1));
	cout << playGame(snakeQueue, applePos, dirInfo, boardSize) << endl;
	return (0);
}