#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<int>> dp;
string n, m;
int answer = 0;
int f(int a, int b) {
	int& ret = dp[a][b];
	if (ret != -1) return ret;
	if (a == 0 || b == 0 || n[a-1] != m[b-1]) ret = 0;
	else ret = f(a - 1, b - 1) + 1;
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	dp.assign(n.size() + 1, vector<int>(m.size() + 1,-1));
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			answer = max(answer, f(i+1,j+1));
		}
	}
	cout << answer;
	return 0;
}