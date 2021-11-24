#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class positionInfo {
public:
    int r;
    int c;
    int cost;
};
const pair<int, int> d[] = { {-1,0},{0,1},{1,0},{0,-1} };
const int INF = 987654321;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    vector<vector<int>> miro(n,vector<int>(m));
    vector<vector<int>> miroMinimalCosts(n, vector<int>(m, INF));
    queue<positionInfo> v;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m;j++) {
            miro[i][j] = a[j]-'0';
        }
    }
    v.push({ 0,0,0 });
    miroMinimalCosts[0][0] = 0;
    while (!v.empty()) {
        positionInfo pi = v.front();  v.pop();
        if (pi.cost > miroMinimalCosts[pi.r][pi.c]) continue;
        for (int i = 0; i < 4; i++) {
            int nextr = pi.r + d[i].first;
            int nextc = pi.c + d[i].second;
            if (0 <= nextr && nextr < n && 0 <= nextc && nextc < m 
                && miroMinimalCosts[nextr][nextc] > pi.cost + miro[nextr][nextc])
            {
                miroMinimalCosts[nextr][nextc] = pi.cost + miro[nextr][nextc];
                v.push({ nextr, nextc, pi.cost + miro[nextr][nextc] });
            }
        }
    }
    cout << miroMinimalCosts[n - 1][m - 1];
    return 0;
}