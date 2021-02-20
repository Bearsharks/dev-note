#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = "a" + s + "a";
	stringstream anss;
	int segcnt = 0;
	int numofdot = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '.') {
			int l = i;
			do {
				i++;
			} while (i <= n && s[i] == '.');
			i--;
			segcnt++;
			numofdot += i - l + 1;
		}
	}
	for (int i = 0; i < m; i++) {
		int idx;
		char c;
		cin >> idx >> c;
		if (c == '.' && s[idx] != '.') {
			s[idx] = '.';
			numofdot++;
			if (s[idx - 1] == '.' && s[idx+1] == '.') {
				segcnt--;
			}
			if (s[idx - 1] != '.' && s[idx + 1] != '.') {
				segcnt++;
			}
		}
		else if (c != '.' && s[idx] == '.') {
			s[idx] = c;
			numofdot--;
			if (s[idx - 1] == '.' && s[idx + 1] == '.') {
				segcnt++;
			}
			if (s[idx - 1] != '.' && s[idx + 1] != '.') {
				segcnt--;
			}
		}
		
		anss << numofdot - segcnt << "\n";
	}
	cout << anss.str();
	return 0;
}