#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	long long remain = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long tmp = max((remain + v[i]) / k , remain / k + !!(remain % k));
		remain = max(remain + v[i] - k * tmp, (long long)0);
		ans += tmp;
	}
	ans += remain > 0;
	cout << ans;
	return 0;
}