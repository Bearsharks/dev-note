#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int v;
	cin >> v;
	int a[10];
	double d[10];
	int mx = 0;
	double mxcnt = 0;
	for (int i = 1; i < 10; i++) {
		cin >> a[i];
		d[i] = (double)v / a[i];
		if (d[i] >= mxcnt) {
			mx = i;
			mxcnt = d[i];
		}
	}
	v -= (int)d[mx] * a[mx];

	vector<int> ans(d[mx], mx);
	int size = d[mx];
	if (size == 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < size; i++) {
		bool isChanged = false;
		for (int j = 9; j > mx; j--) {
			if (a[j] <= a[mx] + v) {
				ans[i] = j;
				v += a[mx] - a[j];
				isChanged = true;
				break;
			}
		}
		if (!isChanged) break;
	}
	for (int i = 0; i < size; i++) {
		cout << ans[i];
	}
	return 0;
}