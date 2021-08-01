#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> dp;
int n;
int f(vector<int>& money, int cur) {
    int& ret = dp[cur];
    if (ret != -1) return ret;
    return ret = max(f(money, cur + 2) + money[cur], f(money, cur + 1));
}

int solution(vector<int> money) {
    n = money.size();
    dp.assign(money.size(), -1);
    dp[money.size() - 1] = money.back();
    dp[money.size() - 2] = max(money[money.size() - 2], money.back());
    int r1 = f(money, 1);
    dp.assign(money.size(), -1);
    dp[money.size() - 1] = 0;
    dp[money.size() - 2] = money[money.size() - 2];
    int r2 = f(money, 0);
    return max(r1, r2);
}
int main() {
    cout << solution({ 3,2,1,3 });
    return 0;
}