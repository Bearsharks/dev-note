#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<pair<int, int>> v;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		v.push_back({ i,i });
	}

	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			v.push_back({ i-1, i });
		}
		
	}
	for (int i = 0; i < v.size(); i++) {
		int left = v[i].first - 1;
		int right = v[i].second + 1;
		if (left >= 0 && right < n && s[left] == s[right]) {
			v.push_back({ left,right });
		}
	}
	sort(v.begin(), v.end());

	unsigned long long ans = 0;
	for (vector<pair<int, int> >::iterator i = v.begin(); i != v.end(); i++) {
		vector<pair<int, int>>::iterator tgt = lower_bound(i, v.end(), make_pair( i->second+1, 0 ));
		ans += v.end() - tgt;
	}

	cout << ans;
	return 0;
}