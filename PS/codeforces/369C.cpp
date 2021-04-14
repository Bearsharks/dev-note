#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

long long d = 1000000;
vector<vector<int>> v(100001);
vector<int> p(100001);
vector<bool> isvisit(100001);
vector<int> noc(100001);
unordered_set<long long> problemRoad;
queue<int> leafs;

void findParent(int cur, int parent) {
	p[cur] = parent;
	bool isleaf = true;
	int childcnt = 0;
	for (int c : v[cur]) {
		if (c != parent) {
			findParent(c, cur);
			isleaf = false;
			childcnt++;
		}
	}
	if (isleaf) {
		leafs.push(cur);
	}
	noc[cur] = childcnt;
}

void repair(int cur) {
	if (cur == 0) return;
	long long road = (cur > p[cur]) ? cur * d  + p[cur] : p[cur] * d + cur;
	problemRoad.erase(road);
	if (!isvisit[p[cur]]) {
		isvisit[p[cur]] = true;
		repair(p[cur]);
	}	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		if (c == 2) {
			long long road = (a > b) ? a * d + b: b * d + a;
			problemRoad.insert(road);
		}
	}
	
	findParent(1,0);
	vector<int> ans;
	while (!leafs.empty()) {
		int cur = leafs.front();
		leafs.pop();
		if (cur == 1) continue;

		long long road = (cur > p[cur]) ? cur * d + p[cur] : p[cur] * d + cur;
		if ( problemRoad.count(road) ) {
			repair(cur);
			ans.push_back(cur);
		}
		if (--noc[p[cur]] == 0) {
			leafs.push(p[cur]);
		}
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout  << i << " ";
	}

	return 0;
}