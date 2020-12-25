#include <vector>
#include <map>
using namespace std;

class dsu {
public:
	dsu() {
	}
	dsu(int n):parent(n),rank(n,1) {
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
		if (rank[u] == rank[v]) rank[v]++;
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

template <typename T>
class mapped_dsu {
public:
	mapped_dsu() {
	}
	mapped_dsu(map<T,int> m) :mp(m), d(m.size()) {
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
	dsu d;
};