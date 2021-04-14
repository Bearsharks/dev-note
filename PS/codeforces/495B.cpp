#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "infinity";
		return 0;
	}

	int ans = 0;
	a = a - b;
	int cur = 1;


	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			if(i > b) ans++;
			if(a/i > b && a/i != i) ans++;
		}
	}
	cout << ans;
	return 0;
}