#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> isResort(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> isResort[i];
    }
    vector<int> v(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    
    int ansi = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (isResort[i]) {
            int cur = v[i];
            int candimx = 1;
            while (cur != 0 && cnt[cur] == 1) {
                candimx++;
                cur = v[cur];
            }
            if (mx < candimx) {
                ansi = i;
                mx = candimx;
            }
        }        
    }
    
    cout << mx << "\n";
    
    vector<int> ans = { ansi };
    int cur = v[ansi];
    while (cur != 0 && cnt[cur] == 1) {
        ans.push_back(cur);
        cur = v[cur];
    }
    for (vector<int>::reverse_iterator i = ans.rbegin(); i != ans.rend(); i++) {
        cout << *i << " ";
    }
    return 0;
}

