#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,k;

	cin >> n>>m>>k;
	map<int,int> mp;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mp[a]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		mp[a]--;
	}
	int prev = 0;
	for (map<int, int>::reverse_iterator ri = mp.rbegin(); ri != mp.rend();ri++) {
		prev += ri->second;
		if (prev > 0) {
			cout << "YES";
			return 0;
		}

	}
	cout << "NO";
	return 0;
}