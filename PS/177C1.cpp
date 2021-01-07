#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DSU {
public:
	DSU() {
	}
	DSU(int n) :parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v]) rank[v]++;
	}
	void makeSet() {
		int i = parent.size();
		parent.push_back(i);
		rank.push_back(1);
		size.push_back(1);
	}
	int getSize(int u) {
		return size[find(u)];
	}
	void initSize(int u) {
		size[find(u)] = 0;
	}
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k, m;
	cin >> n >> k;
	DSU dsu(n + 1);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		dsu.merge(a, b);
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if(dsu.find(a) == dsu.find(b))
			dsu.initSize(a);
	}	
	int mx = 0;

	for (int i = 1; i <= n; i++) {
		mx = max(mx, dsu.getSize(i));
	}
	cout << mx;
	return 0;
}