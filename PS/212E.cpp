#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int dfs(vector<vector<pair<int, int>>>& node, int cur, int parent) {
	int result = 0;
	int parenti = -1;
	for (int i = 0, size = node[cur].size(); i < size; i++) {
		pair<int, int>* next = &node[cur][i];
		if (next->first != parent) {
			next->second = dfs(node, next->first, cur) + 1;
			result += next->second;
		}
		else {
			parenti = i;
		}
	}
	if (parenti >= 0) {
		node[cur][parenti].second = node.size() - 2 - result;
	}
	return result;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> node(n+1);
	
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back({ b,0 });
		node[b].push_back({ a,0 });
	}

	dfs(node, 1, 0);

	vector<int> t(5001);
	int tmp = n - 1;
	for (int i = 1; i <= n; i++) {
		unordered_set<int> save;
		for (int j = 0, size = node[i].size(); j < size; j++) {
			vector<int> tmp;
			tmp.push_back(node[i][j].second);
			for (int a : save) {
				tmp.push_back(a + node[i][j].second);
			}
			for (int a : tmp) {
				save.insert(a);
			}
		}
		for (int i : save) {
			t[i]++;
		}
	}
	vector<int> ans;
	for (int i = 1; i < 5001; i++) {
		if (t[i])ans.push_back(i);
	}

	cout << ans.size()-1;
	for (int i = 0; i < ans.size() - 1; i++) {
		cout << "\n" << ans[i] << " " << n - 1 - ans[i];
	}
	
	
	return 0;
}