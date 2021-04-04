#include <iostream>
#include <vector>
using namespace std;

pair<int,int> dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visit, int cur, int length) {
    visit[cur] = true;
    pair<int, int> ret = { length, cur };
    for (pair<int,int> child : graph[cur]) {
        if (!visit[child.first]) {
            pair<int, int> res = dfs(graph, visit, child.first, length+child.second);
            if (res > graph[0][0]) graph[0][0] = res;
            ret = max(res, ret);
        }
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<bool> visit(n+1);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        int input = 0;
        cin >> input;
        while (input != -1) {            
            int d = 0;
            cin >> d;
            graph[id].push_back({ input,d });
            cin >> input;
        }
    }
    graph[0].push_back({ 0,0 });
    dfs(graph, visit, 1, 0);
    int farpoint = graph[0][0].second;
    visit.assign(n + 1, 0);
    graph[0][0] = { 0,0 };
    cout << dfs(graph, visit, farpoint, 0).first;
    return 0;
}
