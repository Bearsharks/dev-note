#include <iostream>
#include <vector>
using namespace std;

bool canMerge(vector<int>& v1, vector<int>& v2) {
	if (v1.size() == 1 || v2.size() == 1) {
		return true;
	}
	else if ((v2[0] - *(++v1.rbegin())) > 1 || (v2[1] - v1.back()) > 1) {
		return true;
	}
	return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v;
	int ans = 1;
	vector<int> cur;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (cur.empty() || cur.back() < a) {
			cur.push_back(a);
		}
		else {
			v.push_back(cur);
			cur.clear();
			cur.push_back(a);
			
		}
	}
	v.push_back(cur);	
	ans = (int)v[0].size() + (v.size() > 1);
	for (int i = 1,size = v.size() ; i < size; i++) {
		ans = max(ans, (int)v[i].size() + (v.size() > 1));
		if (canMerge(v[i-1],v[i])) {
			ans = max(ans, (int)v[i - 1].size() + (int)v[i].size());	
		}
	}
	cout << ans;
	return 0;
}