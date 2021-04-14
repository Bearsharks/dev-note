#include <iostream>
#include <vector>	
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,x,y;
	cin >> n>>m >> x>>y;
	vector<vector<int>> visit(n+1,vector<int>(m+1));
	string s;
	cin >> s;
	int size = s.size();
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (!visit[x][y]) {
			cnt++;
			visit[x][y] = 1;
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
		if (s[i] == 'L' && y - 1 > 0) {
			--y;
		}
		else if (s[i] == 'R' && y + 1 <= m) {
			++y;
		}
		else if (s[i] == 'U' && x - 1 > 0) {
			--x;
		}
		else if (s[i] == 'D' && x + 1 <= n) {
			++x;
		}
	}
	cout << n*m - cnt;
	return 0;
}