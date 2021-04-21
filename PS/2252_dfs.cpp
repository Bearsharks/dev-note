#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(32001);
vector<bool> isvisit(32001);
vector<int> answer;
int n, m;
void DFS(int cur) {
	isvisit[cur] = true;
	for (int i : graph[cur]) {
		if(!isvisit[i]) DFS(i);
	}
	answer.push_back(cur);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!isvisit[i]) {
			DFS(i);
		}		
	}
	
	for (vector<int>::reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}