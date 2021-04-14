#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v;
	int i = 0;
	for (char c : s) {
		if (c == '0') v.push_back(i);
		i++;
	}
	int total = v.size();
	int ans = INT_MAX;
	for (int i = k; i < total; i++) {
		int mx = i;
		int mn = i - k;
		int tgt = (v[mx] + v[mn]) / 2;
		while (mx > mn) {
			int mid = (mx + mn) / 2;
			if (v[mid] == tgt) {
				mx = mid;
				break;
			}
			else if (v[mid] < tgt) {
				mn = mid+1;
			}
			else {
				mx = mid;
			}
		}
		int candi = max(v[i] - v[mx], v[mx] - v[i - k]);
		if (tgt != v[mx]) {
			int candi2 = max(v[i] - v[mx - 1], v[mx - 1] - v[i - k]);
			candi = min(candi, candi2);
		}
		ans = min(ans, candi);
	}
	cout << ans;
	return 0;
}