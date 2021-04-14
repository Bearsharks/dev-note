#include <iostream>
#include <cstring>

using namespace std;
typedef unsigned long long ull;

int dp[1000][1000];
string s1, s2;
int n = 0,m = 0;
int f(int l1, int l2) {
    if (l1 >= n || l2 >= m) return 0;
    int& ret = dp[l1][l2];    
    if (ret > -1) return ret;
    int i = l2;
    while (i < m) {
        if (s1[l1] == s2[i]) break;
        i++;
    }
    int isMatch = 0;
    if (i < m) isMatch = 1;
    return ret = max(f(l1 + 1, i+1) + isMatch, f(l1 + 1, l2));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    memset(dp, -1, sizeof(int)*1000*1000);
    cout << f(0,0);
    return 0;
}