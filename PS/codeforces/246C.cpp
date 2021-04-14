#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	unordered_map<int, vector<int>> m;
	m[0] = vector<int>();
	for(int i = 0; i < n && m.size()-1 < k;i++){		
		vector<int> found;
		for (unordered_map<int, vector<int>>::iterator iter = m.begin(); iter != m.end() && m.size() - 1 + found.size() < k; iter++) {
			if (m.count(iter->first + v[i]) == 0) found.push_back(iter->first);
		}
		for (int a : found) {
			m[a + v[i]] = m[a];
			m[a + v[i]].push_back(v[i]);
		}
	}
	int cur = 0;
	m.erase(0);
	for (unordered_map<int, vector<int>>::iterator iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->second.size();
		for (int i : iter->second) {
			cout << " " << i;
		}
		cout << "\n";
		cur++;
	}
	return 0;
}