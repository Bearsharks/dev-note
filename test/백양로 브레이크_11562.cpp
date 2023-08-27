#include <iostream>
#include <vector>
using namespace std;

int n, m;
void fwsp(vector<vector<int>>& adj) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(n+1, 987654321));
    for (int i = 1; i <= n; i++) {
        v[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a][b] = 0;
        v[b][a] = !c;
    }
    fwsp(v);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[a][b] << "\n";
    }
 
    return 0;
}