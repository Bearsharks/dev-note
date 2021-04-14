#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s, dst;	
	cin >> s >> dst;
	s = "a" + s;
	int alpha[128] = { 0, };
	for (char c : dst) {
		alpha[c]++;
	}
	int cur[128] = { 0, };
	int i = 0;
	int n = dst.size();
	for (; i < n; i++) {
		cur[s[i]]++;
	}

	int ans = 0;
	for (int size = s.size(); i < size; i++) {
		cur[s[i - n]]--;
		cur[s[i]]++;
		int any = cur['?'];
		for (int j = 'a'; j <= 'z'; j++) {
			if (cur[j] > alpha[j]) {
				any = -1;
			}
			else if (cur[j] < alpha[j]) {
				any -= (alpha[j] - cur[j]);
			}

			if (any < 0) break;
		}
		if (any == 0)
			ans++;
	}
	cout << ans;
	return 0;
}