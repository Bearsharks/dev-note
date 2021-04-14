#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string bigNumAdd(string n1, string n2){
    int sum = 0;
    string result;

    // 1의 자리부터 더하기
    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1의 자리부터 push 했으므로 뒤집어준다.
    reverse(result.begin(), result.end());
    return result;

}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<string>> dp(101, vector<string>(101,"0"));
    dp[1][0] = "1";
    dp[1][1] = "1";
    for (int i = 2; i <= n; i++) {
        dp[i][0] = "1";
        for (int j = 1; j <= i; j++) {
            dp[i][j] = bigNumAdd(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}
