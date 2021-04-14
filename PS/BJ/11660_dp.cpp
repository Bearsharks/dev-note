#include <iostream>
#include <vector>

using namespace std;
typedef unsigned intull;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> v(n+1, vector<long long>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] += -v[i - 1][j - 1] + v[i-1][j] + v[i][j-1] ;
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >>  y1 >>  x2 >> y2;
        cout << v[x2][y2] - v[x2 ][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}