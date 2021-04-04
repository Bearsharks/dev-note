#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	int cur = n;
	do {
		int de = cur / 10;
		int on = cur % 10;
		cur = on * 10 + (de + on) % 10;
		ans++;
	} while (n != cur);
	cout << ans;
	return 0;
}