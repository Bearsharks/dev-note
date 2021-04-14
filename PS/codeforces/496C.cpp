#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector< pair<int, int> > save;
	for (int i = 1; i < n;i++) {
		save.push_back({ i - 1, i });
	}
	int curc = 0;
	int ans = 0;
	while (!save.empty() && curc < m) {
		vector< pair<int, int> > newsave;
		bool isok = true;
		for (pair<int, int> p : save) {
			if (v[p.first][curc] > v[p.second][curc]) {
				ans++;
				isok = false;
				break;
			}
			if (v[p.first][curc] == v[p.second][curc]) {
				newsave.push_back(p);
			}
		}
		if (isok) {
			save = newsave;
		}
		curc++;
	}
	cout << ans;
	return 0;
}