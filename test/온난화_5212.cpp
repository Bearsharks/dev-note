#include <iostream>
#include <vector>
using namespace std;


pair<int, int> p[] = { {-1,0}, {0,1}, {1,0}, {0, -1} };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int ��, ��;
	cin >> �� >> ��;

	vector<string> ����(��);
	for (int i = 0; i < ��; i++) {
		cin >> ����[i];
	}

	vector<vector<int>> ����(��, vector<int>(��));
	for (int i = 0; i < ��; i++) {
		����[i][0]++;
		����[i][�� - 1]++;// ���η� ä���ֱ�
	}
	for (int j = 0; j < ��; j++) {
		����[0][j]++;
		����[�� - 1][j]++;// ���η� ä���ֱ�
	}
		/*for (int i = 0; i < ��; i++) {
			for (int j = 0; j < ��; j++) {
				cout << ����[i][j];
			}
			cout << "\n";
		}*/

	for (int i = 0; i < ��; i++) {
		for (int j = 0; j < ��; j++) {
			if (����[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					int x = i + p[k].first;
					int y = j + p[k].second;
					if (0 <= x && x < �� && 0 <= y && y < ��) {
						����[x][y]++; // ������ 3�� �̻� �� ���� �ٴٰ� �� ��
					}
				}
			}
		}
	}

		/*cout << "\n";
		for (int i = 0; i < ��; i++) {
			for (int j = 0; j < ��; j++) {
				cout << ����[i][j];
			}
			cout << "\n";
		}*/

	int �� = 99999999, �� = 0, �� = 99999999, �� = 0;
	for (int i = 0; i < ��; i++) {
		for (int j = 0; j < ��; j++) {
			if (����[i][j] >= 3) {
				����[i][j] = '.';
			}
			if (����[i][j] == 'X') {
				// �� �߿��� �� �� �� �� ��� �� ����ֱ�
				�� = min(i, ��);
				�� = max(i, ��);
				�� = min(j, ��);
				�� = max(j, ��);
			}
		}
	}

	int cnt = 0;
	for (int i = ��; i <= ��; i++) {
		for (int j = ��; j <= ��; j++) {
			cnt++;
			cout << ����[i][j];
		}
		cout << "\n";
	}
	if(cnt == 0 ) cout << "X";
	return 0;
}