#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a,b;
	cin >> a >>b;
	int cur = 0;
	int n = a.size();
	while (cur < n && a[cur] == b[cur]) {
		cur++;
	}
	if (cur == n) {
		cout << "No such string";
		return 0;
	}
	if (b[cur] - a[cur] >= 2) {
		a[cur]++;
		cout << a;
		return 0;
	}
	if (b[cur] - a[cur] == 1) {
		for (int i = cur + 1; i < n; i++) {
			if (a[i] != 'z') {
				a[i] = 'z';
				cout << a;
				return 0;
			}
		}
		for (int i = cur + 1; i < n; i++) {
			if (b[i] != 'a') {
				b[i] = 'a';
				cout << b;
				return 0;
			}
		}
	}
	cout << "No such string";
	return 0;
}