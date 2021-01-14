#include <vector>
#include <map>
using namespace std;

class DSU {
public:
	DSU() {
	}
	/*DSU(int n) :parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}*/
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
		pair<int, int> up = set[u];
		pair<int, int> vp = set[v];
		set.erase(u);
		if (vp.first > up.first) vp.first = up.first;
		if (vp.second < up.second) vp.second = up.second;
		set[v] = vp;
		if (rank[u] == rank[v]) rank[v]++;
	}
	void makeSet(pair<int,int> p) {
		int i = parent.size();
		parent.push_back(i);
		rank.push_back(1);
		size.push_back(1);
		for (map<int, pair<int, int>>::iterator iter = set.begin(); iter != set.end(); iter++) {
			pair<int, int> cp = iter->second;
			if (cp.second <= p.first || cp.first >= p.second) continue;
			if (cp.first > p.first) cp.first = p.first;
			if (cp.second < p.second) cp.second = p.second;
			iter->second = cp;
			merge(iter->first, i);
			i = iter->first;
			p = cp;
		}
		for (map<int, pair<int, int>>::reverse_iterator iter = set.rbegin(); iter != set.rend(); iter++) {
			pair<int, int> cp = iter->second;
			if (cp.second <= p.first || cp.first >= p.second) continue;
			if (cp.first > p.first) cp.first = p.first;
			if (cp.second < p.second) cp.second = p.second;
			iter->second = cp;
			merge(iter->first, i);
			i = iter->first;
			p = cp;
		}
	}
	int getSize(int u) {
		return size[find(u)];
	}
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
	map<int,pair<int,int>> set;
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