#include <iostream>
#include <vector>
using namespace std;

int d = 1000000007;
vector<int> dp;
int n;
int f(int cur) {
	if (cur > n) return 0;
	int& ret = dp[cur];
	if (ret != -1) return ret;
	ret = (1 + f(cur + 1) + f(cur + 2)) % d;
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	dp.assign(n + 1, -1);
	cout << (d + f(0) - 1) %d;
	return 0;
}