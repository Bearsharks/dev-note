#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}
	int l = v[0].first;
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (v[i].first - v[i].second > l) {
			cnt++;
			l = v[i].first;
		}
		else if (v[i].first + v[i].second < v[i+1].first) {
			cnt++;
			l = v[i].first + v[i].second;
		}
		else {
			l = v[i].first;
		}
	}
	cout << cnt+min(2,n);
	return 0;
}