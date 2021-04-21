#include <iostream>
#include <cstring>
using namespace std;

int dp[1000][1000];
string s1, s2;
int n = 0, m = 0;
int f(int l1, int l2) {
    if (l1 >= n || l2 >= m) return 0;
    int& ret = dp[l1][l2];
    if (ret > -1) return ret;
    ret = f(l1 + 1, l2);
    ret = max(ret, f(l1, l2 + 1));
    if (s1[l1] == s2[l2]) {
        ret = max(f(l1 + 1, l2 + 1) + 1, ret);
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    memset(dp, -1, sizeof(int) * 1000 * 1000);
    int answer = f(0, 0);
    cout << answer << "\n";
    int l1 = 0, l2 = 0;
    while (answer && l1 < n && l2 < m) {
        if (dp[l1][l2] == dp[l1][l2+1]) {
            l2++;
        }
        else if (dp[l1][l2] == dp[l1 + 1][l2]) {
            l1++;
        }
        else {
            cout << s1[l1];
            l1++;
            l2++;
            answer--;
        }
    }
    return 0;
}