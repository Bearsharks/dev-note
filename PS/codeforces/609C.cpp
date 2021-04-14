#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> v(n);	
	long long mid = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mid += v[i];
	}
	mid /= n;
	long long l = 0;
	long long g = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < mid) {
			l += mid - v[i];
		}
		else if (v[i] > mid+1) {
			g += v[i] - mid - 1;
		}
	}
	long long ans = max(l, g);
	cout << ans;
	return 0;
}