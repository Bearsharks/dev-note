#include <iostream>
#include <vector>
using namespace std;

int s, e;
vector<vector<pair<int, int>>> v;
vector<bool> isVisit;

bool dfs(int idx, int weight) {
    if (idx == e) {
        return true;
    }

    isVisit[idx] = true;

    for (pair<int, int> p : v[idx]) {
        int next = p.first;
        int limit = p.second;

        if (!isVisit[next] && limit >= weight) { // 갈 수 있으면 간다.
            if (dfs(next, weight)) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    v.resize(n + 1);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
        mx = max(c, mx);
    }
    cin >> s >> e;

    int l = 1, r = mx;

    while (l < r) {
        int mid = (r + l) / 2 + 1;
        isVisit.assign(n + 1, false);
        if (dfs(s, mid)) {
            l = mid;
        }
        else r = mid - 1;
    }

    cout << l;

    return 0;
}