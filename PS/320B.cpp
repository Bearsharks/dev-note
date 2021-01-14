#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
public:
	DSU() {
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
	void makeSet(pair<int, int> p) {
		int i = parent.size();
		parent.push_back(i);
		rank.push_back(1);
		size.push_back(1);
		vector<int> mergetgts;
		for (unordered_map<int, pair<int, int>>::iterator iter = set.begin(); iter != set.end(); iter++) {
			pair<int, int> cp = iter->second;
			if ((cp.first < p.first && p.first < cp.second) || (cp.first < p.second && p.second < cp.second)) {
				p.first = min(cp.first, p.first);
				p.second = max(cp.second, p.second);
				mergetgts.push_back(iter->first);
			}			
		}
		if (mergetgts.size() > 0) {
			for (int tgt : mergetgts) {
				merge(tgt, i);
				set.erase(tgt);
			}			
		}
		set[i] = p;
	}
	int getSize(int u) {
		return size[find(u)];
	}
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
	unordered_map<int, pair<int, int>> set;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    DSU dsu;
    while (n--) {
        int oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 1) {
            dsu.makeSet({ a,b });
        }
        else {
            if (dsu.find(a-1) == dsu.find(b-1)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}