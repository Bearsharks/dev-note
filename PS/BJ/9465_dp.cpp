#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int f(vector<int>* v, int n) {
    n--;
    int dp[2][2] = { {v[0][n - 1] + v[1][n] , v[0][n]},{ v[1][n - 1] + v[0][n], v[1][n]} };
    for (int i = n - 2; i >= 0; i--) {
        int prevmx = max(dp[0][1], dp[1][1]);
        int cur0mx = v[0][i] + max(prevmx, dp[1][0]);
        int cur1mx = v[1][i] + max(prevmx, dp[0][0]);
        dp[0][1] = dp[0][0];
        dp[1][1] = dp[1][0];
        dp[0][0] = cur0mx;
        dp[1][0] = cur1mx;
    }
    int prevmx = max(dp[0][1], dp[1][1]);
    int mx = max(dp[0][0], dp[1][0]);
    return max(mx, prevmx);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int> v[2] = { vector<int>(100000), vector<int>(100000) };
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        cout << f(v, n) << "\n";
    }
    return 0;
}