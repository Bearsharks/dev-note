/*
최소 최대 범위가 각 노드별로 주어지고
각 노드와 연결된 엣지가 주어질때,
노드에서 범위안의 어떤 수를 택해서, 엣지로 연결된 노드들끼리는 그 수들의 차이를 구할 수 있을 것이고
그때, 그 차이들의 합이 최대가 되는 값을 고르시오

우선 최대 최소 범위안을 고른다고 했는데 사실 어떻든 최대 최소 둘 중 하나를 골라야
차이를 최대로 할 수 있다 왜냐하면 어떤 노드가 중간값을 가졋다고 하면, 연결된 다른 노드랑의 차이가 줄어든다.
그럼 중간 값을 했을때, 이득이 하나라도 있냐는 것을 따져보면
여기서도 차이가 줄고 저기서도 차이가 줄어서 결국 모든 면에서 손해기 때문에 최대 최소 둘중 하나를 모든
노드에서 골라야 최대가 된다는 것을 알수 있다.

여기서 답의 타입을 int로 잡아서 오버플로가 생겨서 틀렸다.
결국 나는 c번까지 맞출수 있엇는데 할때 먼저 범위를 확인하고 문제를 풀어서
실수를 최대한 줄여보자
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<bool> isStart;
vector<pair<ll, ll>> treeNode;
vector<vector<ll>> graph;

pair<ll, ll> dfs(int cur) {
	isStart[cur] = true;
	ll l = 0, r = 0;
	for (ll adj : graph[cur]) {
		if (!isStart[adj]) {
			pair<ll, ll> beauty = dfs(adj);
			
			l += max(abs(treeNode[cur].first - treeNode[adj].first) + beauty.first,
					abs(treeNode[cur].first - treeNode[adj].second) + beauty.second);
			
			r += max(abs(treeNode[cur].second - treeNode[adj].first) + beauty.first,
				abs(treeNode[cur].second - treeNode[adj].second) + beauty.second);
		}
	}
	return { l, r };
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		treeNode.assign(n, {0,0});
		graph.assign(n, vector<ll>());
		for (int i = 0; i < n; i++) {
			cin >> treeNode[i].first >> treeNode[i].second;
		}
		for (int i = 0; i < n-1; i++) {
			ll a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}
		isStart.assign(n,false);
		pair<ll, ll> beauty = dfs(0);
		cout << max(beauty.first, beauty.second) << "\n";
	}
	return 0;
}