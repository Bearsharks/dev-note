#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int suml = 0;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        suml += v[i];
        int cur = suml * l + (sum - suml) * r;
		if(i > n-i) cur += (2 * i - n - 1) * ql;
		if(i < n-i) cur += (n - 2 * i - 1) * qr;
		ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}

