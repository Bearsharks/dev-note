#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n) {		
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
		}

		sort(v.begin(), v.end());
		set<int> s;
		s.insert(-1);
		s.insert(n);

		long long answer = 0;
		for (int i = 0; i < n; i++) {
			set<int>::iterator cur = s.insert(v[i].second).first;
			set<int>::iterator prev = cur; prev--;
			cur++;
			answer = max((ll)(*cur - *prev - 1) * v[i].first, answer);
		}
		cout << answer << "\n";
		cin >> n;
	}
	
	return 0;
}