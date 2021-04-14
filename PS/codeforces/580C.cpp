#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> cat;
int cnt = 0;
int d = 0;

void dfs(int cur, int parent, int cc) {
	if (cur != 1 && v[cur].size() == 1) {
		cnt++;
		return;
	}
	for (int i : v[cur]) {
		if (i != parent && cat[i] + cc <= d) {
			int nextcc = (cat[i]) ? cc + 1 : 0;
			dfs(i, cur, nextcc);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> d;
	v.assign(n + 1, vector<int>());
	cat.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> cat[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0, cat[1]);
	cout << cnt;
	return 0;
}