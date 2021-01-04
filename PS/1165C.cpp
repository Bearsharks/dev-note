#include<iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    string ans = "";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((ans.size() & 1) == 0 || ans.back() != s[i]) {
            ans += s[i];
        }
        else {
            cnt++;
        }
    }
    if (ans.size() & 1) {
        ans.pop_back();
        cnt++;
    }
    cout << cnt << "\n" << ans;

    return 0;
}