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
			bool �������� = j + 1 < n, �ٹ����� = i + 1 < n;
			//����
			if (dp[i][j][0]) {
				bool �������ΰ������� = �������� && dp[i][j + 1][0] != -1;
				bool �밢�����ΰ������� = �������ΰ������� && �ٹ����� && dp[i+1][j + 1][0] != -1 && dp[i + 1][j][0] != -1;
				if (�������ΰ�������) dp[i][j + 1][0] += dp[i][j][0];
				if (�밢�����ΰ�������) dp[i + 1][j + 1][2] += dp[i][j][0];
			}
			//����
			if (dp[i][j][1]) {				
				bool �����ٷΰ������� = �ٹ����� && dp[i+1][j][0] != -1;
				bool �밢�����ΰ������� = �����ٷΰ������� && �������� && dp[i + 1][j + 1][0] != -1 && dp[i][j+1][0] != -1;
				if (�����ٷΰ�������) dp[i + 1][j][1] += dp[i][j][1];
				if (�밢�����ΰ�������) dp[i + 1][j + 1][2] += dp[i][j][1];
			}
			
			//�밢��
			if (dp[i][j][2]) {
				bool �������ΰ������� = �������� && dp[i][j+1][0] != -1;
				bool �����ٷΰ������� = �ٹ����� && dp[i + 1][j][0] != -1;
				bool �밢�����ΰ������� = �������ΰ������� && �����ٷΰ������� && dp[i + 1][j + 1][0] != -1;
				if (�������ΰ�������) dp[i][j + 1][0] += dp[i][j][2];
				if (�����ٷΰ�������) dp[i + 1][j][1] += dp[i][j][2];
				if (�밢�����ΰ�������) dp[i + 1][j + 1][2] += dp[i][j][2];
			}
		}
	}
	cout << max(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2],0);
	return 0;
}