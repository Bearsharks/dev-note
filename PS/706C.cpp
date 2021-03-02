#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<long long>> dp(2);
vector<int> cost;
vector<string> v;
int n;

long long f(int isR, int cur) {
	long long& ret = dp[isR][cur];
	if (ret != -1) return ret;
	string curstr = v[cur];


	if (isR) {
		ret = cost[cur];
		reverse(curstr.begin(), curstr.end());
	}
	else {
		ret = 0;
	}

	long long result = 1e15+1;
	if (curstr <= v[cur + 1]) {
		result = min(result, f(0, cur + 1));
	}

	string next = v[cur + 1];
	reverse(next.begin(), next.end());
	if (curstr <= next) {
		result = min(result, f(1, cur + 1));
	}
	return ret += result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	cost.push_back(0);
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		cost.push_back(c);
	}
	v.push_back("");
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	dp[0].assign(n + 1, -1);
	dp[1].assign(n + 1, -1);
	dp[0][n] = 0;
	dp[1][n] = cost[n];
	long long result = f(0, 0);
	if (result >= 1e15+1) result = -1;
	cout << result;
	return 0;
}