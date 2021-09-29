#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp(12, vector<ll>(12, -1));
vector<int> info;
ll getBase(int n) {
    ll res = 1;
    while (n--) {
        res *= 10;
    }
    return res;
}
int cal(ll n, int cur) {
    int result = 0;
    int point = 0;
    while (point <= cur) {
        int cur = n % 10;
        if (cur > info[point]) {
            result += point;
        }
        else if (info[point] > 0) {
            result -= point;
        }
        point++;
        n /= 10;
    }
    return result;
}

ll f(int cur, int remain) {
    ll& ret = dp[cur][remain];
    if (ret != -1) return ret;
    if (cur <= 0 || remain <= 0) {
        if (remain > 9) remain = 9;
        dp[cur][remain] = remain * getBase(cur);
        return dp[cur][remain];
    }
    ret = f(cur - 1, remain);//얻지 않는경우    
    if (remain > info[cur]) {//이번 점수를 얻는경우
        ll candi = 0;
        candi = getBase(cur) * (info[cur] + 1);
        ll a = info[cur] + 1;

        if (a > 9) a = 9;
        candi += f(cur - 1, remain - a);
        if (cal(candi, cur) > cal(ret, cur)) {//초과일 때, 현재 점수를 얻는걸 선택해야함
            ret = candi;
        }
    }
    return ret;
}
vector<int> solution(int n, vector<int> info_) {
    info = info_;
    reverse(info.begin(), info.end());
    vector<int> answer;
    ll result = f(10, 10);
    int d = cal(result, 10);
    if (d < 1) return { -1 };
    while (result) {
        answer.push_back(result % 10);
        result /= 10;
    }
    while (answer.size() < 11) {
        answer.push_back(0);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    solution(10, { 4,3,2,1,0,0,0,0,0,0,0 });
    return 0;
}