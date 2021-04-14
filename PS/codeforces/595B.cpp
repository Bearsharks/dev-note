#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long d = 1e9 + 7;
	long long n, k;
	cin >> n >> k;
	n /= k;
	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long max = 0;
	long long oneek = 1;
	for (int i = 1; i < k; i++) {
		oneek *= 10;
	}
	max = oneek * 10 - 1;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		long long cnt = max / a[i] + 1;
		long long impocnt;
		if(b[i] == 0){
			impocnt = (oneek * (b[i] + 1) - 1) / a[i] + 1;
		}
		else {
			impocnt = (oneek * (b[i] + 1) - 1) / a[i] - (oneek * b[i] - 1) / a[i];
		}		
		ans = (ans * (cnt - impocnt)) % d;
	}
	cout << ans;
	return 0;
}