#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ll a,b;
	cin >> a>>b;
	string s;
	cin >> s;
	vector<pair<int, int>> v;
	ll x = 0;
	ll y = 0;
	for (char c : s) {
		if (x == a && y == b) {
			cout << "Yes";
			return 0;
		}
		v.push_back({ x, y });
		if (c == 'R') {
			x++;
		}
		else if (c == 'L') {
			x--;
		}
		else if (c == 'U') {
			y++;
		}
		else {
			y--;
		}		
	}
	if (x == a && y == b) {
		cout << "Yes";
		return 0;
	}
	for (pair<int, int> p : v) {
		if (x == 0 && y == 0){
			break;
		}
		if (x == 0 || y == 0) {
			if (x == 0 && (p.first == a) && (b - p.second) % y == 0 && (b - p.second) / y > 0) {
				cout << "Yes";
				return 0;
			}
			else if (y == 0 && (p.second == b) && (a - p.first) % x == 0 && (a - p.first) / x > 0) {
				cout << "Yes";
				return 0;
			}
		}
		else {
			if ((a - p.first) * y == (b - p.second) * x && (b - p.second) % y == 0 && (b - p.second) / y > 0) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}