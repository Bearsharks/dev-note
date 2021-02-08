#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long sum = 0;
	vector<long long> v(n);
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		mx = max(mx, v[i]);
	}
	long long test = sum / (n - 1) + !!(sum % (n - 1));
	mx = max(mx, sum / (n - 1) + !!(sum % (n - 1)));
	cout << mx;
		

	return 0;
}