#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n ,q;
	cin >> n >> q;
	string str;
	cin >> str;
	str = " " + str;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;

		int cur = l;
		int d = 1;
		char prev = '0';
		int previ = 0;
		int result[10] = { 0, };
		string s = str;
		do {
			if ('0' <= s[cur] && s[cur] <= '9') {
				result[s[cur] - '0']++;
				s[cur]--;
				prev = s[cur];
				previ = cur;
			}
			else if ('<' == s[cur] || '>' == s[cur]) {
				d = s[cur] - '=';
				if (prev == '<' || prev == '>') {
					s[previ] = '0' - 1;
				}
				prev = s[cur];
				previ = cur;
			}			
			cur += d;
		} while (l <= cur && cur <= r);

		for (int i = 0; i < 10; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}