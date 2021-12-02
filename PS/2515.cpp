#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;

vector<int> dp;
long long k = 1000000;
vector<pair<int, int>> v;
int f(int cur) {
    if (cur >= n) return 0;
    int& ret = dp[cur];
    if (ret != -1) return ret;
    int next = upper_bound(v.begin() + cur, v.end(), make_pair(v[cur].first + s, -1)) - v.begin();
    return ret = max(f(next) + v[cur].second, f(cur + 1));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    v.assign(n, { 0,0 });
    dp.assign(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int start = upper_bound(v.begin(), v.end(), make_pair(s, -1)) - v.begin();
    cout << f(start);
    return 0;
}