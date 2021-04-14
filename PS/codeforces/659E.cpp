#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
	DSU() {
	}
	DSU(int n) :parent(n), rank(n, 1){
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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(n+1);
	DSU dsu(n+1);
	vector<int> cnt(n + 1);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		dsu.merge(a, b);
	}
	int ans = 0;
	int isocnt = 0;
	for (int i = 1; i <= n; i++) {
		int cur = dsu.find(i);
		cnt[cur]++;
		isocnt += v[i].size() == 0;
		cnt[cur] -= max((int)v[i].size() - 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		ans += max(cnt[i]/2,0);
	}
	cout << ans + isocnt;
	return 0;
}