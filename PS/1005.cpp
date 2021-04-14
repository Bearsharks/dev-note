#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void dfs(vector<bool>& visit, vector<vector<int>>& graph, vector<int>& result,int cur) {
    visit[cur] = true;
    for (int c : graph[cur]) {
        if(!visit[c]) dfs(visit, graph, result, c);
    }
    result.push_back(cur);
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ts;
        vector<int> time(n+1);
        vector<int> cost(n + 1);
        vector<vector<int>> child(n + 1);
        int tgt;        
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }
        for(int i = 1; i <= k; i++) {
            int a, b;
            cin >> a >> b;
            child[a].push_back(b);
        }
        cin >> tgt;
        
        int test = 0;
        vector<bool> visit(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) dfs(visit, child, ts, i);
        }
        reverse(ts.begin(), ts.end());
        for (int cur : ts) {
            if (cur == tgt) break;
            for (int child_ : child[cur]) {
                time[child_] = max(time[cur]+cost[cur], time[child_]);
            }
        }
        cout << time[tgt] + cost[tgt] << "\n";
    }   
    return 0;
}