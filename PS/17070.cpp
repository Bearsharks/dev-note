#include <iostream> 
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n,vector<int>(3)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a) dp[i][j][0] = -1;			
		}
	}
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j][0] == -1) continue;
			bool 열범위내 = j + 1 < n, 줄범위내 = i + 1 < n;
			//가로
			if (dp[i][j][0]) {
				bool 다음열로갈수있음 = 열범위내 && dp[i][j + 1][0] != -1;
				bool 대각선으로갈수있음 = 다음열로갈수있음 && 줄범위내 && dp[i+1][j + 1][0] != -1 && dp[i + 1][j][0] != -1;
				if (다음열로갈수있음) dp[i][j + 1][0] += dp[i][j][0];
				if (대각선으로갈수있음) dp[i + 1][j + 1][2] += dp[i][j][0];
			}
			//세로
			if (dp[i][j][1]) {				
				bool 다음줄로갈수있음 = 줄범위내 && dp[i+1][j][0] != -1;
				bool 대각선으로갈수있음 = 다음줄로갈수있음 && 열범위내 && dp[i + 1][j + 1][0] != -1 && dp[i][j+1][0] != -1;
				if (다음줄로갈수있음) dp[i + 1][j][1] += dp[i][j][1];
				if (대각선으로갈수있음) dp[i + 1][j + 1][2] += dp[i][j][1];
			}
			
			//대각선
			if (dp[i][j][2]) {
				bool 다음열로갈수있음 = 열범위내 && dp[i][j+1][0] != -1;
				bool 다음줄로갈수있음 = 줄범위내 && dp[i + 1][j][0] != -1;
				bool 대각선으로갈수있음 = 다음열로갈수있음 && 다음줄로갈수있음 && dp[i + 1][j + 1][0] != -1;
				if (다음열로갈수있음) dp[i][j + 1][0] += dp[i][j][2];
				if (다음줄로갈수있음) dp[i + 1][j][1] += dp[i][j][2];
				if (대각선으로갈수있음) dp[i + 1][j + 1][2] += dp[i][j][2];
			}
		}
	}
	cout << max(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2],0);
	return 0;
}