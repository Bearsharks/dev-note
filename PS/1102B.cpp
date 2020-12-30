#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n , k;
    cin >> n >> k;
    vector<int> cnt(5001);
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    if (n < k) {
        cout << "NO";
        return 0;
    }

    int mx = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(++(cnt[num[i]]));
        mx = max(cnt[num[i]], mx);
    }
    if (k < mx) {
        cout << "NO";
        return 0;
    }
    if (k > mx) {
        cnt.assign(k, 0);
        for (int i = 0; i < n && k > mx; i++) {
            if (!cnt[ans[i]]) {
                cnt[ans[i]] = 1;
                continue;
            }
            ans[i] = k--;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}