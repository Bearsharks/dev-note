#include <string>
#include <vector>

void topology_sort(vector<bool>& visit, vector<vector<int>>& graph, vector<int>& result, int cur) {
    visit[cur] = true;
    for (int c : graph[cur]) {
        if (!visit[c]) dfs(visit, graph, result, c);
    }
    result.push_back(cur);
    return;
}
//reverse(result.begin(), result.end());