#include <iostream>
#include <vector>
using namespace std;

int nei[8] = { -1,-1,-1,0,0,1,1,1 };
int nej[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> cp(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if (a == '.') v[i][j] = 0;
			else v[i][j] = 1;
		}
	}

	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				cnt += v[i + nei[k]][j + nej[k]];
			}
			if (cnt == 8) {
				for (int k = 0; k < 8; k++) {
					cp[i + nei[k]][j + nej[k]] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(v[i][j] != cp[i][j]){
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
	return 0;
}