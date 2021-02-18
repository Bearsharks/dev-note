#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int> weight(n+1);
	vector<int> order(m+1);
	vector<int> isEx(n+1);
	vector<int> st;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> order[i];
		if (!isEx[order[i]]) {
			isEx[order[i]] = true;
			st.push_back(order[i]);
		}
	}
	reverse(st.begin(), st.end());
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int cur = order[i];
		vector<int> save;
		int total = 0;
		while (st.back() != cur) {
			total += weight[st.back()];
			save.push_back(st.back());
			st.pop_back();
		}
		st.pop_back();
		while (!save.empty()) {
			st.push_back(save.back());
			save.pop_back();
		}
		st.push_back(cur);
		ans += total;
	}
	cout << ans;
	return 0;
}