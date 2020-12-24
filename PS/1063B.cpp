#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(26);
	for (char c: s) {
		v[c - 'a']++;
	}
	
	for (int i = 0; i < 26;i++) {
		while (v[i]--) {
			printf("%c", 'a' + i);
		}
	}
	return 0;
}