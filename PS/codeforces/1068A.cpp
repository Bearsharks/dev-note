#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long n,m,k,l;
	cin >> n >> m >> k >> l;
	unsigned long long a = (k + l) % m > 0;
	a += (k + l) / m;
	if (n >= a * m) cout << a;
	else cout << -1;
	return 0;
}