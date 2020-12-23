#include <iostream>
#include <vector>
using namespace std;

int nei[8] = { -1,-1,-1,0,0,1,1,1 };
int nej[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n>>m;

	vector<vector<int>> v(1000,vector<int>(1000));
	vector<vector<int>> fob(1000, vector<int>(1000));

	for (int i = 0; i < n; i++) {		
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if (a == '.') v[i][j] = 0;
			else v[i][j] = 1;

			if (i == 0 || i == n - 1) fob[i][j] = 1;
			if (j == 0 || j == m - 1) fob[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) {
				for (int k = 0; k < 8; k++) {
					int curi = i + nei[k], curj = j + nej[k];
					if (curi >= 0 && curi < n && curj >= 0 && curj < m) {
						fob[curi][curj] = 1;
					}					
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int curi = i + nei[k], curj = j + nej[k];
					if (curi >= 0 && curi < n && curj >= 0 && curj < m) {
						cnt += fob[curi][curj];
					}
					else {
						cnt++;
					}
				}
				if (cnt == 8) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
	return 0;
}