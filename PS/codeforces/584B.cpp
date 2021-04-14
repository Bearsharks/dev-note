	#include <iostream>
	using namespace std;

	long long d = 1e9 + 7;
	long long power(long long a, long long n) {
		long long result = a;
		while (--n) {
			result = (result * a) % d;
		}
		return result;
	}

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		int n;
		cin >> n;
		long long ans = power(27, n) - power(7, n);
		if (ans < 0) ans += d;
		cout << ans;
		return 0;
	}