#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp(101,vector<int>(10001,-1));
vector<int> memory(101);
vector<int> cost(101);
int n,m;
int f(int cur, int maxCost) {
    if (cur >= n) return 0;
    int& ret = dp[cur][maxCost];
    if (ret >= 0)  return ret;
    ret = f(cur + 1, maxCost);
    if (maxCost - cost[cur] >= 0) {
        ret = max(f(cur + 1, maxCost - cost[cur]) + memory[cur], ret);
    }
    return     ret;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    int mx = 10000;
    int mn = 0;
    while (mn < mx) {
        int mid = (mx + mn) / 2;
        if (f(0, mid) >= m) {
            mx = mid;
        }
        else {
            mn = mid + 1;
        }
    }
    cout << mx;
    return 0;
}
