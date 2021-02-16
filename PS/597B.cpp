#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i  < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	
	int cnt = 1;
	int cur = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first > v[cur].second) {
			cnt++;
			cur = i;
		}else if (v[i].second < v[cur].second) {
			cur = i;
		}
	}
	cout << cnt;
	return 0;
}