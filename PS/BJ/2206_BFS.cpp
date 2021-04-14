#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> mp;
vector<vector<int>> visit;
vector<pair<int, int>> d = { {-1,0},{0,1},{1,0},{0,-1} };
struct param {
    int y; int x; int breakflag; int cnt;
};
int n, m;
int bfs() {
    queue<param> q;
    visit[0][0] = 1;
    q.push({ 0,0,1,1 });
    while (!q.empty()) {
        param p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = p.x + d[i].second;
            int nexty = p.y + d[i].first;
            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && (visit[nexty][nextx] & p.breakflag) == 0) {
                if (mp[nexty][nextx] == '1' && p.breakflag == 1) {
                    if (nextx == m - 1 && nexty == n - 1) return p.cnt + 1;
                    visit[nexty][nextx] = visit[nexty][nextx] | p.breakflag;
                    q.push({ nexty, nextx, 2, p.cnt + 1 });
                }
                else if (mp[nexty][nextx] == '0') {
                    if (nextx == m - 1 && nexty == n - 1) return p.cnt + 1;
                    visit[nexty][nextx] = visit[nexty][nextx] | p.breakflag;
                    q.push({ nexty, nextx, p.breakflag, p.cnt + 1 });
                }
            }
        }
    }
    return -1;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    mp.assign(n, "");
    visit.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    if (n == 1 && m == 1) cout << 1;
    else cout << bfs();
    return 0;
}