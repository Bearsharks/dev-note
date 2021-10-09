#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int 사람수, 파티수;
	cin >> 사람수 >> 파티수;
	
	int 진실을아는자의수;
	cin >> 진실을아는자의수;
	if (진실을아는자의수 == 0) {
		cout << 파티수;
		return 0;
	}
	vector<int> 진실을아는자(진실을아는자의수);	
	for (int i = 0; i < 진실을아는자의수; i++) {
		cin >> 진실을아는자[i];
	}
	vector<int> 파티온사람들;
	DSU dsu(사람수 + 1);
	for (int i = 0; i < 파티수; i++) {
		int 파티사람수, 온사람대표;
		cin >> 파티사람수 >> 온사람대표;
		파티온사람들.push_back(온사람대표);
		for (int j = 1; j < 파티사람수; j++) {
			int 파티온사람;
			cin >> 파티온사람;
			dsu.merge(파티온사람, 온사람대표);
		}
	}	
	for (int i = 1; i < 진실을아는자.size(); i++) {
		dsu.merge(진실을아는자[0], 진실을아는자[i]);
	}
	int 거짓말가능한파티수 = 0;
	int 진실아는사람대표 = dsu.find(진실을아는자[0]);
	for (int 온사람 : 파티온사람들) {
		거짓말가능한파티수 += (진실아는사람대표 != dsu.find(온사람));
	}
	cout << 거짓말가능한파티수;
	return 0;
}