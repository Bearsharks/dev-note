#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(2,vector<int>(3001,-1));
vector<vector<int>> abc(3, vector<int>(3001));
int n;

int f(int cnt, int cur) {
	int& ret = dp[cnt][cur];
	if (ret != -1) return ret;
	if (cnt == 0) {
		ret = max(ret, abc[0][cur] + f(1, cur + 1));
		ret = max(ret, abc[1][cur] + f(0, cur + 1));
	}
	else if (cnt == 1) {
		ret = max(ret, abc[1][cur] + f(1, cur + 1));
		ret = max(ret, abc[2][cur] + f(0, cur + 1));
	}	
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> abc[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> abc[1][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> abc[2][i];
	}
	dp[0][n-1] = abc[0][n - 1];
	dp[1][n-1] = abc[1][n - 1];
	cout << f(0, 0);
	return 0;
}