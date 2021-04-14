#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(1000003);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[a]++;
	}
	int ans = 0;
	for (int i = 0; i < 1000001; i++) {
		if (v[i]) {
			v[i + 1] += v[i] / 2;
			if ((v[i] & 1)) {
				ans++;
			}
		}
	}
	while(v[1000001]) {
		if (v[1000001] & 1) {
			v[1000001]--;
			ans++;
		}
		v[1000001] /= 2;
	}
	cout << ans;
	return 0;
}