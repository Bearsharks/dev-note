#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class DSU {
public:
	DSU() {
	}
	DSU(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return v;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
		return v;
	}
	void makeSet() {
		int i = parent.size();
		parent.push_back(i);
		rank.push_back(1);
	}
private:
	vector<int> parent;
	vector<int> rank;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<string> v(n);
	vector<bool> isVisit(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '1') {
				dsu.merge(i, j);
			}
		}
	}
	map<int, vector<int>> m;
	map<int, vector<int>> order;
	for (int i = 0; i < n; i++) {
		m[dsu.find(i)].push_back(nums[i]);
		order[dsu.find(i)].push_back(i);
	}
	vector<int> ans(n);
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++) {
		sort(i->second.begin(), i->second.end());
		for (int k = 0, size = i->second.size(); k < size; k++) {
			ans[order[i->first][k]] = i->second[k];
		}

	}
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}