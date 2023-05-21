#include <vector>
#include <iostream>
using namespace std;

vector<vector<long long>> dp(201, vector<long long>(201));
long long f(int tgt, int cnt) {
    long long& ret = dp[tgt][cnt];
    if (ret) return ret;
    if (cnt == 1) return ret = 1;
    ret = 0;
    for (int i = 0; i <= tgt; i++) {
        ret = (ret + f(tgt - i, cnt - 1)) % 1000000000;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << f(n, k);
    return 0;
}