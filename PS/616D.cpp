#include <iostream>
#include <vector>	
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	map<int, int> m;
	int last = 0;
	int cnt = 0;
	int ans = 0;
	pair<int, int> anspair;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
		cnt++;
		while(m.size() > k) {
			if (m[v[last]]-- == 1) {
				m.erase(v[last]);				
			}
			cnt--;
			last++;
		}
		if (cnt > ans) {
			anspair = { last,i };
			ans = cnt;
		}		
	}
	cout << anspair.first+1 << " " << anspair.second+1;
	return 0;
}