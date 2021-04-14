#include <iostream>
#include <queue>
using namespace std;

void plusbtn(string& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		s[i]++;
		if (s[i] > '9')s[i] = '0';
	}
}
/*
void shiftbtn(string& s, string& ans, int k, int n) {
	for (int i = 0; i < n; i++) {
		if (ans[i] == s[k + i]) {
			continue;
		}		
		else {
			if (ans[i] > s[k + i]) {
				ans = s.substr(k,n);
			}
			break;
		}
	}
}*/
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	string ans = s;
	s += s;
	int ansi = 0;
	
	for (int i = 0; i < 10 ; i++) {
		if (i != 0) {
			plusbtn(s);
		}
		for (int j = 0; j < n; j++) {
			string candi = s.substr(j, n);
			if (ans > candi) {
				ans = candi;
			}
			//shiftbtn(s, ans, j,n);
		}
	}

	cout << ans;
	return 0;
}