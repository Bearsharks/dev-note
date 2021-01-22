#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (n == 1 && k == 0) {
		cout << 1;
		return 0;
	}
	if (n == 1 || n / 2 > k) {
		cout << -1;
		return 0 ;
	}
	int tgt = k - n / 2 + 1;
	int p = tgt * 2;
	cout << tgt << " " << p << " ";
	int remain = n - 2;
	for (int i = 2; i < tgt && remain > 1; i+=2) {
		cout << i - 1 << " " << i << " ";
		remain -= 2;
	}
	for (int i = tgt + 2; i < p && remain > 1; i += 2) {
		cout << i - 1 << " " << i << " ";
		remain -= 2;
	}
	int i = p + 2;
	while (remain--) {
		cout << i++ << " ";
	}
	return 0;
}
