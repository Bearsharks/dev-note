#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int INF = 987654321;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int a, b, c, d,e;
	cin >> a >> b >> c >> d;
	vector<int> minimal = { a,b,c,d };
	vector<vector<int>> v;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d >> e;
		v.push_back({ a,b,c,d,e });
	}
	int answer = INF;
	vector<int> s;
	int total = pow(2, N);
	vector<vector<int>> dp(total, vector<int>(5, -1));
	dp[0] = { 0,0,0,0,0 };
	
	for (int i = 1; i < total; i++) {
		int k = 0;
		while (!(i & (1 << k)) && k < 15) k++;
		int prev = k >= 15 ? 0 : i - (1 << k);
		dp[i][0] = dp[prev][0] + v[k][0];
		dp[i][1] = dp[prev][1] + v[k][1];
		dp[i][2] = dp[prev][2] + v[k][2];
		dp[i][3] = dp[prev][3] + v[k][3];
		dp[i][4] = dp[prev][4] + v[k][4];
		if (dp[i][0] >= minimal[0] && dp[i][1] >= minimal[1] && dp[i][2] >= minimal[2] && dp[i][3] >= minimal[3]
			&& answer >= dp[i][4]) {
			if (answer > dp[i][4] )s.clear();
			s.push_back(i);
			answer = dp[i][4];
		}
	}
	cout << answer;
	
	return 0;
}