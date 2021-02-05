#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n>>k;
	vector<int> v(n + 1);
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 2; i <= n; i++) {
		d[i] = -(i - 1) * (n - i) * v[i];
		for (int j = 1; j < i; j++) {
			d[i] += v[j] * (j - 1);
		}
	}
	

	return 0;
}