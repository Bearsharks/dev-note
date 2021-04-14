#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<pair<long long, long long>> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
		m.push_back({abs(a) + abs(b), i});
	}
	sort(m.begin(), m.end());

	long long cnt = 0;
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		pair<int, int> p = v[m[i].second];
		stringstream one;
		stringstream two;
		if (p.first > 0) {
			one << "1 " << p.first << " R\n";
			two << "1 " << p.first << " L\n";
			cnt += 2;
		}
		else if(p.first < 0) {
			one << "1 " << -p.first << " L\n";
			two << "1 " << -p.first << " R\n";
			cnt += 2;
		}		
		if (p.second > 0) {
			one << "1 " << p.second << " U\n";
			two << "1 " << p.second << " D\n";
			cnt += 2;
		}
		else if (p.second < 0) {
			one << "1 " << -p.second << " D\n";
			two << "1 " << -p.second << " U\n";
			cnt += 2;
		}
		one << "2\n";
		two << "3\n";
		cnt += 2;
		ans.emplace_back(one.str());
		ans.emplace_back(two.str());
	}

	cout << cnt << "\n";
	for (int i = 0, size = ans.size(); i < size; i++) {
		cout << ans[i];
	}
	return 0;
}