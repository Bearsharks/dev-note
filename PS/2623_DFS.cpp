#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int cur, vector<vector<int>>& graph, vector<int>& isvisit, vector<int>& answer) {
	isvisit[cur] = isvisit[cur] | 1;
	for (int next : graph[cur]) {
		if (!isvisit[next]) {
			dfs(next, graph, isvisit, answer);
		}
		else if (isvisit[next] == 1) {
			answer.push_back(0);
		}
	}
	isvisit[cur] = isvisit[cur] | 2;
	answer.push_back(cur);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1);
	for (int i = 0; i < m; i++) {
		int size, cur,next;
		cin >> size >> cur;
		while (--size) {
			cin >> next;
			graph[cur].push_back(next);
			cur = next;
		}
	}
	vector<int> isvisit(n + 1);
	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		if(!isvisit[i]) dfs(i, graph, isvisit, answer);
	}
	if (answer.size() != n) {
		cout << 0;
	}
	else {
		for (vector<int>::reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++) {
			cout << *iter << "\n";
		}
	}	
	return 0;
}