#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	int ones = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];		
		ones += v[i];
		ans += ones * !v[i];
	}
	cout << ans;
	return 0;
}