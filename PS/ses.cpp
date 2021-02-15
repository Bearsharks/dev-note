#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n>>m;
	vector<vector<int>> v(n+2, vector<int>(m+2));
	vector<vector<int>> ul(n + 2, vector<int>(m + 2));
	vector<vector<int>> ur(n + 2, vector<int>(m + 2));
	vector<vector<int>> dl(n + 2, vector<int>(m + 2));
	vector<vector<int>> dr(n + 2, vector<int>(m + 2));
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <=m; j++) {
			cin >> v[i][j];
		}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ul[i][j] = max(ul[i - 1][j], ul[i][j - 1]) + v[i][j];
		}		
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			dl[i][j] = max(dl[i + 1][j], dl[i][j - 1]) + v[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			ur[i][j] = max(ur[i - 1][j], ur[i][j + 1]) + v[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			dr[i][j] = max(dr[i + 1][j], dr[i][j + 1]) + v[i][j];
		}
	}
	int ans = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {			
			ans = max(ans, ul[i][j-1] + dr[i][j+1] + dl[i+1][j] + ur[i-1][j]);
			ans = max(ans, ul[i-1][j] + dr[i+1][j] + dl[i][j-1] + ur[i][j+1]);
		}
	}
	cout << ans;
	return 0;
}