#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int last = v.back();
    vector<int> dp(last + 1, 0);
    
    int ans = 1;

    vector<int>::iterator i = v.begin();
    if (*i == 1) i++;
    for (; i != v.end(); i++) {
        unordered_set<int> divisors;
        int cur = *i;
        divisors.insert(cur);
        for (int j = 2; j*j <= cur; j++) {
            if (cur % j == 0) {
                divisors.insert(j);
                divisors.insert(cur/j);
            }
        }
        int mx = 1;
        for (int k : divisors) {
            mx = max(++dp[k], mx);
        }
        for (int k : divisors) {
            dp[k] = mx;
        }
        ans = max(mx, ans);
    }

    cout << ans;
    return 0;
}