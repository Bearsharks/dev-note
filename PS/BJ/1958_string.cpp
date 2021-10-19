#define LOCAL
#include "test.h"

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;


vector<vector<vector<int>>> dp(20, vector<vector<int>>(20,vector<int>(20,-1)));
string n, m, p;
int answer = 0;
int f(int a, int b, int c) {
	int& ret = dp[a][b][c];
	if (ret != -1) return ret;
	if (a == 0 || b == 0 || c == 0) ret = 0;
	else if (n[a - 1] == m[b - 1] && m[b - 1] == p[c - 1]) {
		ret = f(a - 1, b - 1, c - 1) + 1;
	}
	else {
		ret = max(f(a - 1,b,c), f(a, b-1, c));
		ret = max(ret, f(a, b, c-1));
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	dp.assign(n.size()+1, vector<vector<int>>(m.size()+1, vector<int>(p.size()+1, -1)));
	cout << f(n.size(), m.size(), p.size());
	debug(dp);
	return 0;
}