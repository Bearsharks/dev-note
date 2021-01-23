#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> ans;
	bool direc = true;
	for (int i = 1; i <= n; i++) {
		if (direc) {
			for (int j = 1; j <= m; j++) {
				ans.push_back({ i, j });
			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				ans.push_back({ i, j });
			}
		}
		direc = !direc;		
	}
	int ansi = 0;
	for (int i = 0; i < k-1; i++) {
		cout << 2 << " " << ans[ansi].first << " " << ans[ansi].second << " " << ans[ansi+1].first << " " << ans[ansi+1].second << "\n";
		ansi+=2;
	}
	cout << ans.size() - ansi << " ";
	for (; ansi < ans.size(); ansi++) {
		cout <<ans[ansi].first << " " << ans[ansi].second << " ";
	}
	return 0;
}
