#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> ans;
	vector<int> isNotPrime(n+1);
	for (int i = 2; i * i <= n; i++) {
		if (!isNotPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isNotPrime[j] = 1;
			}
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (!isNotPrime[i]) {
			int cur = i;
			while (cur <= n) {
				ans.push_back(cur);
				cur *= i;
			}
		}
	}
	cout << ans.size() << "\n";

	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}