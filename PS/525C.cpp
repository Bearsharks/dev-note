#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	long long ready = 0;
	for (int i = n-1; i >= 1; i--) {
		if (v[i] - v[i - 1] <= 1) {
			if (ready) {
				ans += ready * v[i - 1];
				ready = 0;
			}
			else ready = v[i - 1];
			i--;
		}
	}
	cout << ans;
	return 0;
}