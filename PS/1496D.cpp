#include <iostream>
#include <vector>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> v;
	int k;
	cin >> k;
	bool isinc = true;
	int cnt = 0;
	int mx = -1;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (k < a == isinc) {
			cnt++;			
		}
		else {
			isinc = !isinc;
			v.push_back(cnt);
			mx = max(cnt, mx);
			cnt = 1;			
		}
		k = a;
	}
	if (cnt > 0) {
		v.push_back(cnt);
		mx = max(cnt, mx);
	}

	if (mx & 1) {
		cout << 0;
		return 0;
	}

	int mxcnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == mx) mxcnt++;
	}
	if (mxcnt > 2) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < v.size(); i++) {
		if (v[i] == mx && v[i] == v[i - 1] && (i&1)){
			cout << 1;
			return 0;
		}		
	}
	cout << 0;
	return 0;
}