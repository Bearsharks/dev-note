#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n+1);
	vector<int> r(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		r[a] = i;
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		bool isOk = r[v[i]] > r[v[i-1]];
		if (!isOk) {
			ans = n - i + 1;
			break;
		}
	}
	cout << ans;
	return 0;
}