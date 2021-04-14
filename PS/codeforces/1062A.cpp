#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> v(n + 1);
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	v.push_back(1001);

	int cons = 1;
	int ans = 0;


	for (int i = 1; i < n + 2; i++) {
		if (v[i] - v[i - 1] == 1) cons++;
		else {
			if (cons > 2) ans = max(ans, cons - 2);
			cons = 1;
		}
	}
	if (cons > 2) ans = max(ans, cons - 2);
	cout << ans;
	return 0;
}