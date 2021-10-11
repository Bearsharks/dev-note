#include <iostream>
#include <vector>
using namespace std;

struct node {
	int val;
	int p = -1;
	int l = -1;
	int r = -1;
};

void dfs(vector<node>& v,int cur) {
	if (v[cur].l != -1) {
		dfs(v, v[cur].l);
	}
	if (v[cur].r != -1) {
		dfs(v, v[cur].r);
	}
	cout << v[cur].val << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int prev = -1;
	cin >> prev;
	vector<node> v;
	v.push_back({ prev });
	int val;
	while (cin >> val) {
		if (val == EOF) break;
		v.push_back({ val });
		int cur = 0;
		while (v.back().p == -1) {
			int next;
			if (v[cur].val < val) {
				next = v[cur].r;
				if (next == -1) {
					v[cur].r = v.size() - 1;
					v.back().p = cur;
				}
			}
			else {
				next = v[cur].l;
				if (next == -1) {
					v[cur].l = v.size() - 1;
					v.back().p = cur;
				}
			}
			cur = next;
		}
	}
	dfs(v, 0);
	return 0;
}	