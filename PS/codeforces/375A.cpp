#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> t = { 1,6,8,9 };
	vector<int> asdf(7);
	do {
		int k = 1;
		int result = 0;
		for (int i = 0; i < 4; i++) {
			result += t[i] * k;
			k *= 10;
		}
		asdf[result % 7] = result;
	} while(next_permutation(t.begin(), t.end()));
	string s;
	cin >> s;
	vector<int> cnt(10);
	for (char c : s) {
		cnt[c - '0']++;
	}
	--cnt[1];
	--cnt[6];
	--cnt[8];
	--cnt[9];
	int curmod = 10000 % 7;
	int cur = 0;
	vector<int> ans;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cur = (cur + curmod * i) % 7;
			curmod = (curmod * 10) % 7;
		}
	}

	for (int i = 9; i >= 1; i--) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i;
		}
	}
	if(cur == 0) cout << asdf[0];
	else cout << asdf[7 - cur];	
	for (int j = 0; j < cnt[0]; j++) {
		cout << 0;
	}
	return 0;
}