#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dp(1001000, -1);
vector<pair<int,int>> v(101);
int n;
int sum;

int f(int t, int w, int cur) {
	if (cur > n) return 0;
	int& ret = dp[t * 200 + w * 1000 + cur];
	if (ret != -1) return ret;
	int newt = t - v[cur].first;
	int neww = w + v[cur].second;
	int ret = 0;
	if (neww <= newt) {
		ret = v[cur].first + f(newt, neww, cur + 1);
	}
	return ret = max(ret, f(t, w, cur + 1));
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
		sum += v[i].first;
	}
	cout << sum - f(0, 0, 1);
	return 0;
}