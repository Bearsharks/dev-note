#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		int mid = m / 2 + (m & 1);
		vector<pair<int,int>> f(n+1);
		vector<vector<int>> sche(n + 1);
		
		f[0].first = -1;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int a;
				cin >> a;
				f[a].first++;
				f[a].second = a;
				sche[a].push_back(i);
			}
		}
		if (n == 1) {
			if (m == 1) {
				cout << "YES\n1\n";
			}
			else {
				cout << "NO\n";
			}
			continue;
		}

		sort(f.begin(), f.end(),greater<pair<int,int>>());

		vector<int> ans(m);
		vector<int> cnt(n+1);
		int firi = f[0].second;
		int fircnt = f[0].first;
		int sei = f[1].second;
		int secnt = f[1].first;
		
		if (fircnt > mid && secnt > mid) {
			set<int> firok;
			for (int sch : sche[firi]) {
				firok.insert(sch);
				ans[sch] = firi;
				cnt[firi]++;
			}
			vector<int> duplicate;
			for (int sch : sche[sei]) {
				if (firok.count(sch)) duplicate.push_back(sch);
				else {
					ans[sch] = sei;
					cnt[sei]++;
				}
			}
			int test = 1;
			for (int i : duplicate) {
				if (cnt[firi] > mid) {
					cnt[firi]--;
					cnt[sei]++;
					ans[i] = sei;
				}
			}
		}
		f.pop_back();
		bool isok = true;
		for (vector<pair<int, int>>::reverse_iterator i = f.rbegin(); i != f.rend() && isok;i++) {
			for (int j : sche[i->second]) {
				if (ans[j] == 0) {
					ans[j] = i->second;
					cnt[i->second]++;
					if (cnt[i->second] > mid) {
						isok = false;
						break;
					}
				}
			}			
		}
		if (isok) {
			cout << "YES\n";
			for (int i = 0; i < m; i++) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}
		
	}
	return 0;
}