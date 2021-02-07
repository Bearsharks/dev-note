#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ull n;
	cin >> n;

	ull pow3 = 3;
	ull cur = n;
	while (cur > 1) {
		if (cur % 3 == 0) {
			pow3 *= 3;
			cur /= 3;
		}
		else {
			break;
		}
	}
	cout << n / pow3 + !!(n % pow3) << "\n";
	return 0;
}