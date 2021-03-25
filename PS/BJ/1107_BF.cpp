#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tgt, m;
	cin >> tgt >> m;
	vector<int> btn(10,1);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		btn[a] = 0;
	}

	int ans = abs(100 - tgt);
	for (int i = 0; i <= 888888; i++) {
		vector<int> digits;
		int candi = i;
		if (candi == 0) {
			digits.push_back(0);
		}
		else {
			while (candi > 0) {
				digits.push_back(candi % 10);
				candi /= 10;
			}
		}		
		reverse(digits.begin(), digits.end());
		int cnt = 0;
		for (int j : digits) {
			cnt += btn[j];
		}
		//누르기 가능하면
		if (cnt == digits.size()) {
			ans = min(abs(i - tgt) + cnt, ans);
		}
	}
	cout << ans;
	return 0;
}