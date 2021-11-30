#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int>(n,0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a-1][b-1] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = v[i][j] || v[i][k] * v[k][j];
			}
		}
	}
	int answer = 0;
	int mid = (n + 1) >> 1;
	for (int i = 0; i < n; i++) {
		int hcnt = 0;
		int lcnt = 0;
		for (int j = 0; j < n; j++) {
			hcnt += v[i][j];
			lcnt += v[j][i];
		}
		answer += hcnt >= mid || lcnt >= mid;
	}
	cout << answer;
	return 0;
}