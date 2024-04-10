#include <iostream>

struct FISH {
	int x;
	int y;
	int dir;
};

int ans;

using namespace std;

const int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};
const int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};

void print_map(int map[][4], int depth) {
	std::cout << "=============================" << depth << "=============================\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << (map[i][j] + 1) << ' ';
		std::cout << '\n';
	}
	std::cout << "=============================" << depth << "=============================\n";
}

void copy_map(int new_map[][4], int origin[][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++)
			new_map[y][x] = origin[y][x];
	}
}

void copy_fish(FISH new_fish[], FISH origin[]) {
	for (int i = 0; i < 16; i++)
		new_fish[i] = origin[i];
}

int eat_fish(int map[][4], FISH fish[], FISH *shark) {
	int fish_num;

	fish_num = map[shark->y][shark->x];
	shark->dir = fish[fish_num].dir;

	map[shark->y][shark->x] = -1;
	fish[fish_num].x = -1;
	fish[fish_num].y = -1;
	fish[fish_num].dir = -1;
	return fish_num + 1;
}

void solution(int map[][4], FISH fish[], FISH shark, int sum, int depth) {
	FISH cur_fish[16];
	int cur_map[4][4];

	// 1. 맵 / 물고기 복사
	copy_map(cur_map, map);
	copy_fish(cur_fish, fish);

	// 2. 상어 위치 물고기 생사 확인
	if (cur_map[shark.y][shark.x] < 0)
		return ;
	// 3. 상어 섭취
	sum += eat_fish(cur_map, cur_fish, &shark);
	if (ans < sum)
		ans = sum;
	// 4. 물고기 대이동 : 상어와 벽만 못지나감. 죽은 물고기랑 교환 가능
	for (int i = 0; i < 16; i++) {
		int nx;
		int ny;
		int nd;
		int cx;
		int cy;

		cx = cur_fish[i].x;
		cy = cur_fish[i].y;
		if (cx < 0)
			continue ;
		for (int dir = cur_fish[i].dir; dir < cur_fish[i].dir + 8; dir++) {
			nd = dir % 8;
			nx = cx + dx[nd];
			ny = cy + dy[nd];
			
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue ;
			if (nx == shark.x && ny == shark.y)
				continue ;
			break ;
		}
		if (cur_map[ny][nx] != -1) {
			int target = cur_map[ny][nx];

			cur_fish[target].y = cy;
			cur_fish[target].x = cx;

			cur_fish[i].y = ny;
			cur_fish[i].x = nx;
			cur_fish[i].dir = nd;

			cur_map[ny][nx] = i;
			cur_map[cy][cx] = target;
		}
		else {
			cur_fish[i].y = ny;
			cur_fish[i].x = nx;
			cur_fish[i].dir = nd;

			cur_map[ny][nx] = i;
			cur_map[cy][cx] = -1;
		}
	}
	// 5. 상어 이동 위치 백트래킹 : 빈 자리 못먹고 벽 못지나감.
	for (int step = 1; step < 4; step++) {
		int ny = shark.y + dy[shark.dir] * step;
		int nx = shark.x + dx[shark.dir] * step;
		FISH next_shark;

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			break ;
		if (cur_map[ny][nx] != -1) {
			next_shark.x = nx;
			next_shark.y = ny;
			solution(cur_map, cur_fish, next_shark, sum, depth + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	FISH fish[16];
	FISH shark;
	int map[4][4];

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int fish_num;
			int dir;

			cin >> fish_num;
			cin >> dir;
			--fish_num;
			--dir;
			map[y][x] = fish_num;
			fish[fish_num].x = x;
			fish[fish_num].y = y;
			fish[fish_num].dir = dir;
		}
	}
	shark.x = 0;
	shark.y = 0;
	solution(map, fish, shark, 0, 1);
	cout << ans << '\n';
	return (0);
}