#include <vector>
#include <map>
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
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return v;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v]) rank[v]++;
		return v;
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
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
};

template <typename T>
class mapped_DSU {
public:
	mapped_DSU() {
	}
	mapped_DSU(map<T,int> m) :mp(m), d(m.size()) {
	}
	
	int find(T u) {
		return d.find(mp[u]);
	}
	void merge(T u, T v) {
		d.merge(mp[u],mp[v]);
	}
	void makeSet(T u) {
		mp[u] = mp.size();
		d.makeSet();
	}
private:
	map<T, int> mp;
	DSU d;
};