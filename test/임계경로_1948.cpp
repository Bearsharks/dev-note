#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

struct CostAndFrom {
    int cost;
    vector<int> from;
    bool 포함 = false;
};

vector<CostAndFrom> result;

void lp(vector<vector<pair<int, int>>> graph, int start, int end) {
    result[start].cost = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int cost = get<0>(cur);
        int i = get<1>(cur);
        if (result[i].cost > cost) continue;
        for (pair<int, int> adj : graph[i]) {
            if (adj.first + cost == result[adj.second].cost) {
                result[adj.second].from.push_back(i);
            }
            else if (adj.first + cost > result[adj.second].cost) {
                result[adj.second].cost = cost + adj.first;
                result[adj.second].from = { i };
                pq.push({ adj.first + cost, adj.second });
            }
        }
    }
}

int getAllEdges(vector<vector<int>>& adj) {
    unordered_set<string> edges;
    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            string edge = to_string(i) + " " + to_string(adj[i][j]);
            edges.insert(edge);
        }
    }
    return edges.size();
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    result.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
    }
    int s, e;
    cin >> s >> e;
    lp(graph, s, e);
    result[e].포함 = true;
    queue<int> q;
    q.push(e);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : result[cur].from) {
            if (!result[next].포함) {
                result[next].포함 = true;
                q.push(next);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += result[i].포함 * result[i].from.size();
    }
    cout << result[e].cost << "\n" << cnt;
    return 0;
}