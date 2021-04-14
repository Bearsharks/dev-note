#include <iostream>
#include <vector>
using namespace std;

int f(int i,int j, vector<vector<int>>& dp, vector<vector<int>>& v) {
    int& ret = dp[i][j];
    if (ret) return ret;
    if (i == v.size() - 1) return ret = v[i][j];
    return ret = v[i][j] + max(f(i + 1, j,dp,v), f(i + 1, j + 1, dp, v));    
}

int solution(int n, vector<vector<int>>& v) {
    vector<vector<int>> dp(n, vector<int>(n));
    return f(0,0,dp,v);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }
    cout << solution(n, v);
    return 0;
}
