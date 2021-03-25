#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		if (k == 1) {
			cout << s << "\n";
			continue;
		}
		if (n % k) {
			cout << -1 << "\n";
			continue;
		}
		vector<int> alphacnt(26);
		for (int i = 0; i < n; i++) {
			alphacnt[s[i]-'a']++;
		}
		bool isok = true;
		for (int i = 0; i < 26; i++) {
			if (alphacnt[i] % k) {
				isok = false;
				break;
			}
		}
		if (isok) {
			cout << s << '\n';
			continue;
		}
		alphacnt.assign(26, 0);
		pair<int, int> candi = { -1,-1 };
		int candiremain = 0;
		for (int i = 0; i < n; i++) {
			int alpha = s[i] - 'a';			
			for (int j = alpha + 1; j < 26; j++) {
				alphacnt[j]++;
				int totalneed = 0;
				for (int t = 0; t < 26; t++) {
					int need = k - (alphacnt[t] % k);
					if (need == k) need = 0;
					totalneed += need;
				}
				alphacnt[j]--;
				if (totalneed <= (n - 1 - i) && (n-1-i- totalneed)%k == 0) {
					candiremain = (n - 1 - i - totalneed);
					candi = { i,j};
					break;
				}
			}
			alphacnt[alpha]++;
		}
		s[candi.first] = candi.second + 'a';
		cout << s.substr(0, candi.first + 1);

		alphacnt.assign(26, 0);
		for (int i = 0; i <= candi.first; i++) {
			alphacnt[s[i] - 'a']++;
		}
		for (int i = 0; i < candiremain; i++) {
			cout << "a";
		}
		for (int i = 0; i < 26; i++) {
			while (alphacnt[i] % k != 0) {
				cout << (char)('a' + i);
				++alphacnt[i];
			}
		}
		cout << "\n";
	}
	return 0;
}