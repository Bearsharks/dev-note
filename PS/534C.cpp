#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n, A;
	cin >> n >> A;
	vector<long long> v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 0; i < n; i++){
		long long mn = A - (sum - v[i]);
		long long mx = A - (n - 1);
		cout << max(v[i] - mx, (long long)0) + max(mn - 1, (long long)0) << " ";
	}
	return 0;
}