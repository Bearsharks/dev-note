#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(1);
	cin >> v[0];
	
	set<int> isset;
	int ans = 0;
	int setcnt = 0;

	for (int i = 1; i < k; i++) {
		int a;
		cin >> a;
		if (v[i - 1] != a) v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		if (isset.count(v[i]) == 0) {
			if (setcnt == n) {
				int lastshow = -1;
				set<int> test = isset;
				for (int j = i + 1; j < v.size(); j++) {
					if (test.count(v[j])) {
						lastshow = v[j];
						test.erase(v[j]);
					}
				}
				if (!test.empty()) lastshow = *test.begin();
				isset.erase(lastshow);
				isset.insert(v[i]);
				ans++;
			}
			else {
				setcnt++;
				isset.insert(v[i]);
			}			
		}
	}
	cout << ans;
	return 0;
}