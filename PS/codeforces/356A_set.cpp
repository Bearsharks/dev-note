#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, match;
    cin >> n >> match;
    vector<int> ans(n+1);
    set<int> s;

    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    
    while (match--) {
        int l, r, winner;
        cin >> l >> r >> winner;
        for (set<int>::iterator iter = s.lower_bound(l); iter != s.end() && *iter < r + 1; iter = s.erase(iter)) {
            ans[*iter] = winner;            
        }
        s.insert(winner);
    }

    int k = 1;
    for (int i = 1; i <= n;i++) {
        if (ans[i] == i) ans[i] = 0;
        cout << ans[i] << " ";
    }
    return 0;
}

