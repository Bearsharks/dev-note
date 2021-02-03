#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> color(n + 1);
	unordered_map<int, unordered_set<int>> colormap;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
		colormap[color[i]].insert(color[i]);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		colormap[color[a]].insert(color[b]);
		colormap[color[b]].insert(color[a]);
	}
	pair<int, int> ans = { 0,0 };
	for (unordered_map<int, unordered_set<int>>::iterator i = colormap.begin(); i != colormap.end(); i++) {
		if (ans.first < i->second.size()) {
			ans =  { i->second.size(), i->first};
		}
		else if (ans.first == i->second.size() && ans.second > i->first) {
			ans = { i->second.size(), i->first };
		}		
	}
	cout << ans.second;
	return 0;
}