#include <iostream>
#include <vector>

using namespace std;

int f(vector<pair<int, int>>& item, vector<vector<int>>& dp, int cur, int remain) {
    if (cur < 1 || cur >= dp.size()) return 0;
    int& ret = dp[cur][remain];
    if (ret >= 0) return ret;    
    ret = f(item, dp, cur - 1, remain);
    if (remain >= item[cur].first) {
        ret = max(ret, item[cur].second + f(item, dp, cur - 1, remain - item[cur].first));
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;    
    vector<pair<int,int>> item(n+1);
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    //first 무게 second 가치
    for (int i = 1; i <= n; i++) {
        cin >> item[i].first >> item[i].second;
    }
    cout << f(item, dp, n, k);
    return 0;
}