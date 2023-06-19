#include <vector>
#include <unordered_map>
#include <iostream>
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

bool compare(tuple<int,int,int>& a, tuple<int, int, int>& b) {
	if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
	return get<1>(a) < get<1>(b);
}

int merge(DSU& dsu, vector<pair<int, int>>& data, int key1, int key2) {
	key1 = dsu.find(key1);
	key2 = dsu.find(key2);
	int newRoot = dsu.merge(key1, key2);
	data[newRoot] = { max(data[key1].first, data[key2].first), max(data[key1].second, data[key2].second) };
	return newRoot;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, c, m;;
	cin >> n >> c >> m;
	DSU dsu(n);

	vector<tuple<int, int, int>> cargos;
	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		cargos.push_back({ s,e,v });
	}

	sort(cargos.begin(), cargos.end(), compare);
	vector<pair<int, int>> nextAndRemain(n);
	for (int i = 0; i < n - 1; i++) {
		nextAndRemain[i] = {i + 1, 0};
	}

	int result = 0;
	cout << "\n";
	for (tuple<int, int, int>& t : cargos) {
		int s = get<0>(t), e = get<1>(t), v = get<2>(t);
		cout << s << " " << e << " " << v << "\n";
	}
	cout << "\n";
	for (tuple<int, int, int>& t : cargos) {
		int s = get<0>(t) - 1, e = get<1>(t) - 1, v = get<2>(t);
		// 현재가 끝이 아니면
		// 현재 더 실을 수 있는 값 v 구하기
		// 한칸 앞으로 가기
		int prev = dsu.find(s);
		while (s < e && v > 0) {
			int curRoot = dsu.find(s);
			int cnt = nextAndRemain[curRoot].second;
			int remain = c - cnt;
			v = remain < v ? remain : v; // 더 실을 수 있는 양과 현재까지 가능한 박스 갯수 중 작은 것 선택
			s = nextAndRemain[s].first;
		}

		if (v > 0) { // 실을 수 있다면 싣고 해당 구간 머지
			s = get<0>(t) - 1;
			int prev = dsu.find(s);
			while (s < e) {
				prev = merge(dsu, nextAndRemain, s, prev);
				s = nextAndRemain[prev].first;
			}
			nextAndRemain[prev].second += v;
			result += v;
		}
	}

	cout << result;
	return 0;
}