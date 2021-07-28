#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int s, t;
	cin >> s >> t;
	
	if (s == t) {
		cout << '0';
		return 0;
	}
	if (t == 1) {
		cout << '/';
		return 0;
	}
	
	queue<pair<ll, string>> q;
	unordered_set<int> set;
	q.push({ s,"" });	
	set.insert(s);
	string result = "-1";
	while (!q.empty()) {
		pair<ll, string> cur = q.front(); q.pop();		
		ll x = cur.first * cur.first;
		if (x == t) {
			result = cur.second + "*";
			break;
		}
		if (x < t && set.count(x) == 0) {
			q.push({ x, cur.second + "*" });
			set.insert(x);
		}	
		ll plus = cur.first + cur.first;
		if (plus == t) {
			result = cur.second + "+";
			break;
		}
		if (plus < t && set.count(plus) == 0) {
			q.push({ plus, cur.second + "+" });
			set.insert(plus);
		}
		if (1 == t) {
			result = cur.second + "/";
			break;
		}
		if (1 < t && set.count(1) == 0) {
			q.push({ 1, cur.second + "/" });
			set.insert(1);
		}
	}
	
	cout << result;
	return 0;
}