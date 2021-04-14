#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& v, vector<int>& answer, int cur) {
    for (int i : v[cur]) {
        if (answer[i] == -1) {
            answer[i] = cur;
            dfs(v, answer, i);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> answer(n+1,-1);
    answer[1] = 0;
    dfs(v, answer, 1);
    for (int i = 2; i <= n; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}