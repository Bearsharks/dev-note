#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int graph[16][16];
int n;

int f(int cur, int bit) {
	int& ret = dp[cur][bit];
	if (ret > 0) return ret;	
	if (bit == (1<<n)-2){// 1111110 일때 그러니까 더이상 갈 곳이 없을 때
		return ret = graph[cur][0];
	}
	ret = 987654321;
	for (int i = 1; i < n; i++) {
		//0을 제외하고 아직 안 간곳을 가본다.
		if ((bit & (1 << i)) == 0) {
			ret = min(ret, f(i, (bit | (1 << i))) + graph[cur][i]);
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	cin >> n;

	dp.assign(n, vector<int>(1 << n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) graph[i][j] = 987654321;
		}
	}
	cout << f(0,0);
	return 0;
}