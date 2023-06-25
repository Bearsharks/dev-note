#include <iostream>
#include <vector>
using namespace std;


pair<int, int> p[] = { {-1,0}, {0,1}, {1,0}, {0, -1} };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int 행, 열;
	cin >> 행 >> 열;

	vector<string> 지도(행);
	for (int i = 0; i < 행; i++) {
		cin >> 지도[i];
	}

	vector<vector<int>> 갯수(행, vector<int>(열));
	for (int i = 0; i < 행; i++) {
		갯수[i][0]++;
		갯수[i][열 - 1]++;// 세로로 채워주기
	}
	for (int j = 0; j < 열; j++) {
		갯수[0][j]++;
		갯수[행 - 1][j]++;// 가로로 채워주기
	}
		/*for (int i = 0; i < 행; i++) {
			for (int j = 0; j < 열; j++) {
				cout << 갯수[i][j];
			}
			cout << "\n";
		}*/

	for (int i = 0; i < 행; i++) {
		for (int j = 0; j < 열; j++) {
			if (지도[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					int x = i + p[k].first;
					int y = j + p[k].second;
					if (0 <= x && x < 행 && 0 <= y && y < 열) {
						갯수[x][y]++; // 갯수가 3개 이상 인 땅은 바다가 될 것
					}
				}
			}
		}
	}

		/*cout << "\n";
		for (int i = 0; i < 행; i++) {
			for (int j = 0; j < 열; j++) {
				cout << 갯수[i][j];
			}
			cout << "\n";
		}*/

	int 상 = 99999999, 하 = 0, 좌 = 99999999, 우 = 0;
	for (int i = 0; i < 행; i++) {
		for (int j = 0; j < 열; j++) {
			if (갯수[i][j] >= 3) {
				지도[i][j] = '.';
			}
			if (지도[i][j] == 'X') {
				// 땅 중에서 좌 우 상 하 계산 후 집어넣기
				상 = min(i, 상);
				하 = max(i, 하);
				좌 = min(j, 좌);
				우 = max(j, 우);
			}
		}
	}

	int cnt = 0;
	for (int i = 상; i <= 하; i++) {
		for (int j = 좌; j <= 우; j++) {
			cnt++;
			cout << 지도[i][j];
		}
		cout << "\n";
	}
	if(cnt == 0 ) cout << "X";
	return 0;
}