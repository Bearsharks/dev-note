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
	int sum = 0;
	for (int i : v) {
		if (sum + 1 < i) {
			break;
		}
		sum += i;
	}
	cout << sum + 1;
	return 0;
}