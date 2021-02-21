#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m;

int bfs(vector<set<int>>& graph) {
	vector<bool> isvisit(n+1);
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	isvisit[1] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();		
		if (graph[cur].count(n)) return cnt + 1;
		for (int child : graph[cur]) {
			if (!isvisit[child]) {
				isvisit[child] = true;
				q.push({ child,cnt + 1 });
			}
		}
	}	
	return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	set<int> proto;
	for (int i = 1; i <= n; i++) {
		proto.insert(i);
	}
	vector<set<int>> train(n+1);
	vector<set<int>> bus(n+1, proto);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		train[a].insert(b);
		train[b].insert(a);
		bus[a].erase(b);
		bus[b].erase(a);
	}
	for (int i = 1; i <= n; i++) {
		bus[i].erase(i);
	}
	int ans = 0;
	if (train[1].count(n)) ans = bfs(bus);
	else ans = bfs(train);

	cout << ans;
	return 0;
}