#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int m[26][26] = { 0, };
	int need[26] = { 0, };
	int give[26] = { 0, };
	int cnt = 0;

	pair<int,int> result = { -1,-1 };
	
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			cnt++;
			if (m[t[i] - 'a'][s[i] - 'a']) {
				result = { i + 1,m[t[i] - 'a'][s[i] - 'a'] };
			}
			m[s[i] - 'a'][t[i] - 'a'] = i+1;
			need[t[i] - 'a'] = i + 1;
			give[s[i] - 'a'] = i + 1;
		}
	}
	if (result.first != -1) {
		cnt -= 2;
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (need[i] && give[i]) {
				result = { need[i] , give[i] };
				cnt--;
				break;
			}
		}
	}
	cout << cnt << "\n";
	cout << result.first << " " << result.second;
	return 0;
}