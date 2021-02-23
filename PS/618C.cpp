#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll> x1y1, x2y2;
ll getd(pair<ll, ll>& a, pair<ll, ll>& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool test(pair<ll, ll>& a, pair<ll, ll>& b) {
	return getd(x1y1, a) < getd(x1y1, b);
}
bool isSameLine(pair<ll, ll> p) {
	return (x1y1.second - x2y2.second) * (p.first - x1y1.first) == (x1y1.first - x2y2.first) * (p.second - x1y1.second);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	vector<pair<ll, ll>> copy;
	for (int i =0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	copy = v;
	x1y1 = v[0];
	sort(v.begin(), v.end(), test);
	x2y2 = v[1];
	for (int i = 2; i < n; i++) {
		if (!isSameLine(v[i])) {
			cout << 1 ;
			for (int j = 1; j < n; j++) {
				if (copy[j] == v[1] || copy[j] == v[i]) {
					cout << " " << j+1;
				}
			}			
			break;
		}
	}
	return 0;
}