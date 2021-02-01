#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, k;
	cin >> a >> b >> k;


	vector<int> v(1000001);
	vector<int> primes;
	for (int i = 2; i * i <= b; i++) {
		if (v[i] == 0) {
			for (int j = 2 * i; j <= b; j += i) {
				v[j] = 1;
			}
		}
	}
	for (int i = max(a,2); i <= b; i++) {
		if (v[i] == 0) primes.push_back(i);
	}
	
	if (primes.size() < k) {
		cout << -1;
		return 0;
	}
	int l = primes[k - 1] - a + 1;
	for (int i = k; i < primes.size(); i++) {
		l = max(l, primes[i] - primes[i-k]);
	}
	l = max(l, b - primes[primes.size() - k] + 1);
	cout << l;
	return 0;
}