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
	int �����, ��Ƽ��;
	cin >> ����� >> ��Ƽ��;
	
	int �������ƴ����Ǽ�;
	cin >> �������ƴ����Ǽ�;
	if (�������ƴ����Ǽ� == 0) {
		cout << ��Ƽ��;
		return 0;
	}
	vector<int> �������ƴ���(�������ƴ����Ǽ�);	
	for (int i = 0; i < �������ƴ����Ǽ�; i++) {
		cin >> �������ƴ���[i];
	}
	vector<int> ��Ƽ�»����;
	DSU dsu(����� + 1);
	for (int i = 0; i < ��Ƽ��; i++) {
		int ��Ƽ�����, �»����ǥ;
		cin >> ��Ƽ����� >> �»����ǥ;
		��Ƽ�»����.push_back(�»����ǥ);
		for (int j = 1; j < ��Ƽ�����; j++) {
			int ��Ƽ�»��;
			cin >> ��Ƽ�»��;
			dsu.merge(��Ƽ�»��, �»����ǥ);
		}
	}	
	for (int i = 1; i < �������ƴ���.size(); i++) {
		dsu.merge(�������ƴ���[0], �������ƴ���[i]);
	}
	int ��������������Ƽ�� = 0;
	int ���Ǿƴ»����ǥ = dsu.find(�������ƴ���[0]);
	for (int �»�� : ��Ƽ�»����) {
		��������������Ƽ�� += (���Ǿƴ»����ǥ != dsu.find(�»��));
	}
	cout << ��������������Ƽ��;
	return 0;
}