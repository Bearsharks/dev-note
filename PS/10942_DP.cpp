#include <iostream>
#include <vector>
using namespace std;

int f(vector<int>& v, vector<vector<int>>& dp, int l, int r) {
	int& ret = dp[l][r];
	if (ret > 0) return ret;
	
	if (v[l] == v[r]) {
		if (r - l <= 1) {
			ret = 2;
		}
		else {
			ret = f(v, dp, l + 1, r - 1);
		}		
	}
	else {
		ret = 1;
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int m;
	cin >> m;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;		
		cout << f(v,dp,a,b)-1 << "\n";
	}
	return 0;
}