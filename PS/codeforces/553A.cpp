#include <iostream>
#include <vector>
using namespace std;

int d = 1e9 + 7;
int maxn = 500;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long ans = 1;
	long long cnt = 0;

	vector<vector<long long>> combi(maxn, vector<long long>(maxn));
	combi[0][0] = 1;
	for (int i = 1; i < maxn; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]) % d;
		}
	}

	for (int i = 1; i <= n; i++) {
		int cur;
		cin >> cur;
		cur--;
		ans = (ans * combi[(i + cnt) + cur - 1][cur]) % d;
		cnt += cur;
	}
	cout << ans;
	return 0;
}