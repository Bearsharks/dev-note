#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long k, a, b;
	cin >> k >> a >> b;
	if (a == 0 || b == 0 || (a > 0 && b < 0) || (a < 0 && b > 0)) {
		cout << abs(a / k) + abs(b / k) + 1;
	}
	else{
		a = abs(a);
		b = abs(b);
		if (a > b) swap(a, b);
		cout << abs(b / k) - abs((a - 1) / k);
	}
	return 0;
}