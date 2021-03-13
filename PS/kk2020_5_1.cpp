#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int N;
vector<vector<int>> frame;
bool isBo(int x, int y) {
	if (0 > x || x > N || 0 > y || y > N) return false;
	return frame[x][y] & 2;
}
bool isPil(int x, int y) {
	if (0 > x || x > N || 0 > y || y > N) return false;
	return frame[x][y] & 1;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	frame.assign(n + 1, vector<int>(n + 1));
	N = n;
	int size = build_frame.size();
	for (int i = 0; i < size; i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int kind = build_frame[i][2];
		int dobuild = build_frame[i][3];
		//1이면 기둥 2이면 보 3이면 둘다.
		if (kind == 0 && dobuild == 1) {//기둥 세우기
			if (y == 0 || isBo(x, y) || isBo(x - 1, y) || isPil(x, y - 1)) {//바닥이거나 현재보거나 왼쪽이 보거나 아래 기둥이라면 지을 수 있다.
				frame[x][y] = frame[x][y] | 1;
			}
		}
		else if (kind == 1 && dobuild == 1) {//보 세우기
			if (isPil(x, y - 1) || isPil(x + 1, y - 1) || (isBo(x - 1, y) && isBo(x + 1, y))) {//양옆이 보거나 아래에 기둥이 있거나 오른쪽 아래에 기둥이 있다면  지을 수 있다.
				frame[x][y] = frame[x][y] | 2;
			}
		}
		else if (kind == 0 && dobuild == 0) {//기둥 제거
			if (isPil(x, y + 1) && !isBo(x, y + 1) && !isBo(x - 1, y + 1))continue;
			//보가 없고 위에 기둥인경우 불가능
			if (isBo(x, y + 1) && !isPil(x + 1, y) && (!isBo(x + 1, y + 1) || !isBo(x - 1, y + 1))) continue;
			//위가 보이고, 오른쪽에 기둥이 없고, 위양옆 모두 보가 아니면 불가능				
			if (isBo(x - 1, y + 1) && !isPil(x - 1, y) && (!isBo(x, y + 1) || !isBo(x - 2, y + 1))) continue;
			//왼쪽 위가 보이고, 왼쪽에 기둥이 없고, 그양옆 모두 보가 아니면 불가능
			frame[x][y] = frame[x][y] ^ 1;
		}
		else {//보 제거
			//기둥 있는 경우 아래에 기둥이 없거나 왼쪽에 보가 없다면 불가능
			//양옆에 보가 있는 경우 아래에 기둥이 없고 오른쪽 아래에도 기둥이 없으면 불가능
			if (isPil(x, y) && (!isPil(x, y - 1) && !isBo(x - 1, y))) continue;
			if (isPil(x + 1, y) && (!isPil(x + 1, y - 1) && !isBo(x + 1, y))) continue;
			if (isBo(x - 1, y) && !isPil(x, y - 1) && !isPil(x - 1, y - 1)) continue;
			if (isBo(x + 1, y) && !isPil(x + 1, y - 1) && !isPil(x + 2, y - 1)) continue;
			frame[x][y] = frame[x][y] ^ 2;
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (frame[i][j]) {
				if (frame[i][j] & 1) answer.push_back({ i,j,0 });
				if (frame[i][j] & 2) answer.push_back({ i,j,1 });
			}

		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<int>> inp(8);
	/*inp[0] = { 0,0,0,1 };
	inp[1] = { 2,0,0,1 };
	inp[2] = { 4,0,0,1 };
	inp[3] = { 0,1,1,1 };
	inp[4] = { 1,1,1,1 };
	inp[5] = { 2,1,1,1 };
	inp[6] = { 3,1,1,1 };
	inp[7] = { 2,0,0,0 };
	inp[8] = { 1,1,1,0 };
	inp[9] = { 2,2,0,1 };*/
	inp[0] = { 1,0,0,1 };
	inp[1] = { 1,1,1,1 };
	inp[2] = { 2,1,0,1 };
	inp[3] = { 2,2,1,1 };
	inp[4] = { 5,0,0,1 };
	inp[5] = { 5,1,0,1 };
	inp[6] = { 4,2,1,1 };
	inp[7] = { 3,2,1,1 };
	//inp[8] = { 1,1,1,0 };
	//inp[9] = { 2,2,0,1 };
	vector<vector<int>> res = solution(5, inp);
	return 0;
}