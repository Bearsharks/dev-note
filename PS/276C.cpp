#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    vector<int> cnt(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin()+1, v.end());
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cnt[r]++;
        cnt[l-1]--;
    }

    int prev = 0;
    for (int i = n; i > 0; i--) {
        cnt[i] += prev;
        prev = cnt[i];
    }
    sort(cnt.begin()+1, cnt.end());
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += v[i] * (unsigned long long)cnt[i];
    }
    cout << ans;
    return 0;
}