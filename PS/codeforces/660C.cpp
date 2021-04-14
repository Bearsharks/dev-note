#include <iostream>
#include <vector>
using namespace std;

int findlast(int idx, vector<int>& v) {
	while (idx+1 < v.size() && v[idx + 1] == 1) {
		idx++;
	}
	return idx;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> zero;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 0)zero.push_back(i);
	}
	int ans = 0;
	if (k == 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) cnt++;
			else {
				ans = max(cnt, ans);
				cnt = 0;
			}
		}
		ans = max(cnt, ans);
		cout << ans<< "\n";
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		return 0;
	}
	else {
		int last = n - 1;
		if (zero.size() >= k) {
			last = findlast(zero[k - 1], v);
		}
		
		ans = last + 1;
		int zerosize = zero.size();
		pair<int, int> anspair = { 0, last };
		for (int i = 0; i < zerosize && last < n - 1; i++) {
			last = findlast(last + 1, v);
			if (ans < last - zero[i]) {
				ans = last - zero[i];
				anspair = { zero[i]+1,last };
			}
		}
		for (int i = anspair.first; i <= anspair.second; i++) {
			v[i] = 1;
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
	}
	
	
	return 0;
}