#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void deleteNum(int board[][9], int num, int i, int j) {
	board[i][j] = 0;
	int mask = 511 ^ (1 << (num - 1));
	//행 열
	for (int k = 0; k < 9; k++) {
		board[k][j] &= mask;
		board[i][k] &= mask;
	}
	//박스
	int boxi = i / 3 * 3;
	int boxj = j / 3 * 3;
	for (int k = 0; k < 3; k++) {
		for (int h = 0; h < 3; h++) {
			board[boxi + k][boxj + h] &= mask;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> v(9);
	int board[9][9];
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = 511;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (v[i][j] != '0') {
				deleteNum(board, v[i][j] - '0', i, j);
			}
		}
	}
	queue<pair<int, int>> q;
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if(board[i][j] > 0 && (board[i][j] & (- board[i][j])) == board[i][j]){
				for (int k = 0; k < 9; k++) {
					if (board[i][j] & (1 << k)) {
						v[i][j] = '0' + k + 1;
						deleteNum(board, k + 1, i, j);
						break;
					}
				}
			}
			else {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) { 
		pair<int, int> p = q.front(); q.pop();
		int i = p.first;
		int j = p.second;
		if (board[i][j] == 0) {
			continue;
		}
		else if ((board[i][j] & (-board[i][j])) == board[i][j]) {
			for (int k = 0; k < 9; k++) {
				if (board[i][j] & (1 << k)) {
					v[i][j] = '0' + k + 1;
					deleteNum(board, k + 1, i, j);
					break;
				}
			}
		}
		else {
			q.push(p);
		}		
	}
	
	for (int i = 0; i < 9; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}