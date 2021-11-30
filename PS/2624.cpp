#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> coin;//(°¡Ä¡, °¹¼ö)
vector<vector<int>> dp(10001, vector<int>(101, -1));
int f(int r, int cur) {
    if (r == 0) return 1;
    if (cur >= n) return 0;
    int& ret = dp[r][cur];
    if (ret > -1) return ret;
    ret = 0;
    for (int i = 0; i <= coin[cur].second; i++) {
        if (coin[cur].first * i > r) break;
        ret += f(r - coin[cur].first * i, cur + 1);
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t >> n;
    coin.assign(n, {0,0});
    for (int i = 0; i < n; i++) {
        int value, cnt;
        cin >> coin[i].first >> coin[i].second;
    }
    sort(coin.begin(), coin.end(),greater<pair<int,int>>());
    cout << f(t, 0);


    return 0;
}