#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, mid;
	cin >> n >> mid;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int centor = n >> 1;

	unsigned long long ans = 0;
	if (mid > v[centor]) {
		for (int i = centor; i < n; i++) {
			if (mid <= v[i]) {
				break;
			}
			ans += mid - v[i];
		}
	}else if (mid < v[centor]) {
		for (int i = centor; i >= 0; i--) {
			if (mid >= v[i]) break;
			ans += v[i] - mid;
		}
	}
	cout << ans;
	

	return 0;
}