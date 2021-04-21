#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> v(9);

bool DFS(int cur) {
	if (cur >= 81) {
		return true;
	}
	int i = cur / 9;
	int j = cur % 9;
	if (v[i][j] == '0') {
		//행 열 박스를 보고 가능한 숫자를 찾기
		int mask = 0;
		//행 열
		for (int k = 0; k < 9; k++) {
			mask |= (1 << (v[k][j] - '0'));
			mask |= (1 << (v[i][k] - '0'));
		}
		//박스
		int boxi = i / 3 * 3;
		int boxj = j / 3 * 3;
		for (int k = 0; k < 3; k++) {
			for (int h = 0; h < 3; h++) {
				mask |= (1 << (v[boxi + k][boxj + h] - '0'));
			}
		}
		//작은거부터 적용하고 시도하기
		for (int k = 1; k <= 9; k++) {
			if ((mask & (1 << k)) == 0) {
				v[i][j] = k+'0';
				if(DFS(cur + 1)) return true;
				v[i][j] = '0';
			}
		}
	}
	else {
		return DFS(cur + 1);
	}	
	return false;	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}

	DFS(0);
	
	for (int i = 0; i < 9; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}