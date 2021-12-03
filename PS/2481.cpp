#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    unordered_map<int,int> map;
    vector<int> v(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int cur = 0;
        for (char c : str) {
            cur = (cur << 1) | (c - '0');
        }
        v[i] = cur;
        map[cur] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = v[i] ^ (1 << j);
            if (map.count(cur)) {
                graph[i].push_back(map[cur]);
            }
        }        
    }
    vector<int> parent(n,-1);
    queue<int> q;
    q.push(0);
    parent[0] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nei : graph[cur]) {
            if (parent[nei] == -1) {
                parent[nei] = cur;
                q.push(nei);
            }
        }
    }
    parent[0] = -1;
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        vector<int> answer;
        a--;
        while (a >= 0) {
            answer.push_back(a + 1);
            a = parent[a];
        }
        if (answer.back() != 1) {
            cout << -1 <<"\n";
        }
        else {
            for (int i = answer.size() - 1; i >= 0; i--) {
                cout << answer[i] << " ";
            }
            cout << "\n";
        }
        
        
    }
    return 0;
}