/**
 * N x N 크기의 맵
 * M 마리의 상어
 * 
 * 1. 상어가 자신의 위치에 냄새를 뿌림 (상어의 k번 이동 후 사라짐)
 * 2. 상어 이동 => 상, 하, 좌, 우 중 인접한 칸 중 하나. 다른 상어의 흔적이 있는 칸은 이동을 못한다고 봐도 무방.
 * 	방향 결정 우선순위
 * 	1. 아무 냄새가 없는 칸
 * 	2. 자신의 냄새가 있는 칸.
 * 	이 중 후보가 여러개라면, 상어마다 가지고 있는 방향별 우선순위에 의거한다. 
 * 
 * 3. 만약 이동 후 한 칸에 상어가 여럿이라면, 숫자가 큰 상어를 제외하고 나머지는 없어진다.
 * 
 * 4. 상어가 한 마리만 남을 때 까지의 초를 구한다. 만약 1000초가 지나도 상어가 2마리 이상이면, -1 => 1부터 3까지의 단순 반복. 시뮬레이션은 1000번이 최대.
 * 
 * 로직
 * 
 * 맵 : 상어의 현재 위치 맵, 상어의 흔적 맵(상어의 번호와 생명 있어야함) 2개가 필요함.
 * 상어 배열: 상어 현재 pos와 dir 담고있는 구조체 배열 있음 좋을듯.
 * 
 * 1. 입력 받기
 * 	격자 정보와 상어 마리수, 흔적의 수명
 * 	격자에 상어 입력받기.
 * 	상어별 우선순위 입력받기
 * 2. 시뮬레이션 함수
 * 	1000번 반복함
 * 		흔적맵 순회히며 흔적 -1 해주는 함수
 * 		흔적 맵에 현재 상어들의 위치에 흔적 남겨주는 함수
 * 		상어 배열 순회
 * 			방향 배열을 인자로 받아 아무 냄새가 없는 칸이 있으면, 배열에 방향들을 채우고 bool을 return
 * 			위에서 못찾으면, 방향 배열을 인자로 받아 내 흔적들이 있는 칸들로 가는 방향을 채워줌.
 * 			상어 현재 방향에 대한 우선순위를 찾아 들어가서, 우선순위 4개 순회하며 위에서 채워준 방향 배열에 있으면 해당 방향 리턴.
 * 			방향에 맞게 현재 상어 이동. (만약 상어가 있다면, 상어 삭제)
 * 		
*/

#include <iostream>

#define UP 1 - 1
#define DOWN 2 - 1
#define LEFT 3 - 1
#define RIGHT 4 - 1

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct SHARK {
	int x;
	int y;
	int cur_dir;
	int d_priority[4][4];
};

struct SMELL {
	int shark_idx;
	int life;
};

// 상어 배열
SHARK shark[401];
// 상어 맵
int shark_map[20][20];
// 흔적 맵
SMELL smell_map[20][20];

int total_shark;
int remain_shark;
int map_size;
int max_life;

void print_map() {
	cout << "=====================PRINT MAP=====================\n";
	for (int y = 0; y < map_size; y++) {
		for (int x = 0; x < map_size; x++) {
			cout << shark_map[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "remain shark : " << remain_shark << '\n';
	cout << "===================================================\n";
}

void init_map() {
	for (int y = 0; y < map_size; y++) {
		for (int x = 0; x < map_size; x++) {
			cin >> shark_map[y][x];
			if (shark_map[y][x]) {
				int shark_idx = shark_map[y][x];

				shark[shark_idx].x = x;
				shark[shark_idx].y = y;
			}
		}
	}
}

void init_shark_dir() {
	int dir;

	for (int i = 1; i <= total_shark; i++) {
		cin >> dir;
		--dir;
		shark[i].cur_dir = dir;
	}
}

void init_shark_dir_priority() {
	int dir;

	for (int i = 1; i <= total_shark; i++) {
		for (int j = 0; j < 4; j++) { // 위 아래 왼 오
			for (int k = 0; k < 4; k++) {
				cin >> dir;
				--dir;
				shark[i].d_priority[j][k] = dir;
			}
		}
	}
}

void init_smell_map() {
	for (int y = 0; y < map_size; y++) {
		for (int x = 0; x < map_size; x++) {
			smell_map[y][x].shark_idx = 0;
			smell_map[y][x].life = 0;
		}
	}
}

void delete_smell(int x, int y) {
	if (smell_map[y][x].life == 0)
		smell_map[y][x].shark_idx = 0;
}

void decrease_smell_life() {
	for (int y = 0; y < map_size; y++) {
		for (int x = 0; x < map_size; x++) {
			if (smell_map[y][x].shark_idx)
				smell_map[y][x].life -= 1;
			if (smell_map[y][x].life == 0)
				delete_smell(x, y);
		}
	}
}

void store_smell() {
	for (int i = 1; i <= total_shark; i++) {
		if (shark[i].cur_dir < 0)
			continue ;
		int x;
		int y;

		x = shark[i].x;
		y = shark[i].y;
		smell_map[y][x].life = max_life;
		smell_map[y][x].shark_idx = i;
	}
}

bool no_smell_dirs(int shark_idx, int possible_dir[]) {
	bool found;
	int nx;
	int ny;

	found = false;
	for (int i = 0; i < 4; i++) {
		nx = shark[shark_idx].x + dx[i];
		ny = shark[shark_idx].y + dy[i];

		if (nx < 0 || ny < 0 || nx >= map_size || ny >= map_size)
			continue ;
		if (!smell_map[ny][nx].shark_idx) {
			possible_dir[i] = 1;
			found = true;
		}
	}
	return (found);
}

void my_smell_dir(int shark_idx, int possible_dir[]) {
	int nx;
	int ny;

	for (int i = 0; i < 4; i++) {
		nx = shark[shark_idx].x + dx[i];
		ny = shark[shark_idx].y + dy[i];

		if (nx < 0 || ny < 0 || nx >= map_size || ny >= map_size)
			continue ;

		if (smell_map[ny][nx].shark_idx == shark_idx) {
			possible_dir[i] = 1;
		}
	}
}

void update_shark(int shark_idx, int possible_dir[]) {
	int cur_dir;
	int next_dir = -99899999;
	int nx;
	int ny;
	int cx;
	int cy;

	cur_dir = shark[shark_idx].cur_dir;
	cx = shark[shark_idx].x;
	cy = shark[shark_idx].y;

	for (int i = 0; i < 4; i++) {
		next_dir = shark[shark_idx].d_priority[cur_dir][i];

		if (possible_dir[next_dir])
			break ;
	}
	// 맵 업데이트
	shark_map[cy][cx] = 0; // 현 위치 제거
	nx = cx + dx[next_dir];
	ny = cy + dy[next_dir];

	// 상어 업데이트
	if (shark_map[ny][nx]) { // 가려는 위치에 이미 상어가 있으면 죽임
		shark[shark_idx].x = -1;
		shark[shark_idx].y = -1;
		shark[shark_idx].cur_dir = -1;
		--remain_shark;
	}
	else { // 상어 정보 업데이트
		shark[shark_idx].x = nx;
		shark[shark_idx].y = ny;
		shark[shark_idx].cur_dir = next_dir;

		// 상어 이동 성공, 상어 맵 업데이트
		shark_map[ny][nx] = shark_idx;
	}
}

int simulate() {
	int time;

	time = 0;
	while (time <= 1000) {
		if (remain_shark == 1)
			break ;
		decrease_smell_life();
		store_smell();
		for (int i = 1; i <= total_shark; i++) {
			if (shark[i].cur_dir < 0)
				continue ;
			int possible_dir[4] = {0, };
			
			if (no_smell_dirs(i, possible_dir))
				update_shark(i, possible_dir);
			else {
				my_smell_dir(i, possible_dir);
				update_shark(i, possible_dir);
			}
		}
		++time;
	}
	if (time > 1000)
		return (-1);
	return (time);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> map_size >> total_shark >> max_life;
	remain_shark = total_shark;

	init_map();
	init_shark_dir();
	init_shark_dir_priority();
	cout << simulate() << '\n';
	return (0);
}