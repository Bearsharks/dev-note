#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;
	vector<vector<pair<int,long long>>> graph(v+1);
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a].push_back({ cost, b });
		graph[b].push_back({ cost, a });
	}

	//새로운 정점을 추가할 수 있는 가장 작은 엣지를 추가 시키자
	//그리고 그 엣지에 연결된 정점을 포함시키자
	//추가할 수 있는 가장 작은 엣지가 뭔지 기록해야함
	priority_queue<pair<long long,int>,vector<pair<long long, int>>, greater< pair<long long, int>>> minNode;
	vector<bool> added(v + 1, false);
	vector<int> parent(v + 1);
	vector<pair<int, int>> selectedEdge;
	long long answer = 0;
	minNode.push({ 0,1 });
	parent[1] = 1;
	while (!minNode.empty()) {
		pair<long long, int> cur = minNode.top();
		minNode.pop();
		if (added[cur.second]) continue;
		added[cur.second] = 1;
		answer += cur.first;
		if (parent[cur.second] != cur.second) {
			selectedEdge.push_back({ parent[cur.second], cur.second });
		}	

		for (pair<long long, int> p : graph[cur.second]) {
			if (!added[p.second]) {
				minNode.push(p);
				parent[p.second] = cur.second;
			}
		}
	}
	cout << answer;
	return 0;
}