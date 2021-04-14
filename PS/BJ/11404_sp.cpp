#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fw(vector<vector<int>>& v) {
    int n = v.size();
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j++) {
                v[i][j] = min(v[i][c] + v[c][j], v[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (20000001 <= v[i][j]) v[i][j] = 0;
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n>>m;
    vector<vector<int>> v(n, vector<int>(n, 20000001));
    for (int i = 0; i < m; i++) {
        int h, t, c;
        cin >> h >> t >> c;
        --h;
        --t;
        v[h][t] = min(v[h][t], c);
    }
    for (int i = 0; i < n; i++) {

        v[i][i] = 0;
    }
    fw(v);
    
    return 0;
}
