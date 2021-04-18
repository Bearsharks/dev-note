#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1000001,987654321);
int get(int n) {
	int& ret = dp[n];
	if (ret < 987654321) return ret;
	if (n % 2 == 0) ret = min(ret, get(n / 2));
	if (n % 3 == 0) ret = min(ret, get(n / 3));
	ret = min(ret, get(n - 1));
	return ret+=1;
}

void find(int n) {
	if (n == 1) {
		cout << 1;
		return;
	}
	int next = n - 1;
	if (n % 2 == 0 && dp[n/2] < dp[next]) {
		next = n / 2;
	}
	if (n % 3 == 0 && dp[n / 3] < dp[next]) {
		next = n / 3;
	}
	cout << n << " ";
	find(next);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 3;
	dp[6] = 2;
	cout << get(n) << "\n";
	find(n);
	return 0;
}