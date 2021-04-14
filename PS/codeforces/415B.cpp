#include <iostream>
using namespace std;

typedef unsigned long long ull;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, a,b;
	cin >> n >>a>>b;
	while (n--) {
		ull k;
		cin >> k;
		cout << (a * k % b)/a << " ";
	}
	return 0;
}
