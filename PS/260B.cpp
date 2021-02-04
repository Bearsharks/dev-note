#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string s;
unordered_map<string, int> m;

int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void check(int i) {
	if (s[i+2] != 64 || s[i+5] != 64 ) {
		return;
	}
	int day = s[i] * 10 + s[i + 1];
	int month = s[i + 3] * 10 + s[i + 4];
	if (month <= 0 || month > 12 || day <= 0 || day > date[month]) {
		return;
	}
	int year = s[i + 6] * 1000 + s[i + 7] * 100 + s[i + 8] * 10 + s[i + 9];
	if (year > 2015 || year < 2013) return;
	m[s.substr(i, 10)]++;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s[i] -= '0';
		}
		else {
			s[i] = 64;
		}
	}

	for (int i = 0; i + 9 < n; i++){
		check(i);
	}
	
	int cnt = 0;
	string ans;
	for (unordered_map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
		if (cnt < i->second) {
			ans = i->first;
			cnt = i->second;
		}
	}
	for (int i = 0; i < 10; i++) {
		ans[i] += '0';
	}
	ans[2] = '-';
	ans[5] = '-';
	cout << ans;
	return 0;
}