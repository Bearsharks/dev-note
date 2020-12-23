#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int max = 2 * k + 1;
	int remain = n % (max);
	int cnt = n / max + (remain > 0);
	int cur = remain;
	cout << cnt << "\n";
	if (cnt == 1) {
		cur = n/2 + 1;
	}
	if (remain == 0) {
		cur = k + 1;
	}
	while( cur <= n) {
		cout << cur << " ";		
		cur += 2 * k + 1;
	}	
	return 0;
}