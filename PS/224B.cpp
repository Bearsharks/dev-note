#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0;
	int r = -1;
	
	unordered_map<int,int> m;
	for (int i = 0; i < n; i++) {
		m[v[i]]++;
		if (m.size() == k) {
			r = i;
			break;
		}
	}

	if (m.size() != k) {
		cout << "-1 -1";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		m[v[i]]--;
		if (!m[v[i]]) {
			l = i;
			break;
		}
	}

	cout << l + 1 << " " << r + 1;
	return 0;
}