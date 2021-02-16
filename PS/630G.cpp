#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v = { n + 4,n + 3,n + 2,n + 2,n + 1,n + 1,n,n };
	vector<int> div = { 2,2,2,2,3,3,5 };
	int cur = 0;
	while (!div.empty()) {
		for (int i = 0; i < 8 && !div.empty(); i++) {
			if (v[i] % div.back() == 0) {
				v[i] /= div.back();
				div.pop_back();
			}
		}
	}
	long long ans = 1;
	for (int i = 0; i < 8; i++) {
		ans *= v[i];
	}
	cout << ans;
	

	return 0;
}