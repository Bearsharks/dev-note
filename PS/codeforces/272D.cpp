#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n;
	unordered_map<int, unordered_map<int,int>> mp;
	vector<pair<int, int>> a(n);
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}
	cin >> m;
	for (int i = 0; i < n; i++) {
		pair<int, int> pa = a[i];
		pair<int, int> pb = b[i];
		mp[pa.first][pa.second]++;
		mp[pb.first][pb.second]++;
	}
	long long ans = 1;
	for (unordered_map<int, unordered_map<int, int>>::iterator i = mp.begin(); i != mp.end(); i++) {
		int cnt = 0;
		int samecnt = 0;
		for (unordered_map<int, int>::iterator j = i->second.begin(), last = i->second.end(); j != last; j++) {
			cnt += j->second;
			if (j->second == 2)samecnt++;
		}
		while (cnt > 1) {
			int cur = cnt;
			while ((cur & 1) == 0 && samecnt) {
				cur = cur >> 1;
				samecnt--;
			}
			ans = (ans * (cur % m)) % m;
			cnt--;
		}
	}
	cout << ans;
	return 0;
}