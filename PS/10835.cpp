#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dp(2000,vector<int>(2000,-1));
vector<int> a(2000);
vector<int> b(2000);
int f(int cura,int curb) {
    if (cura >= n || curb >= n) return 0;
    int& ret = dp[cura][curb];
    if (ret != -1) return ret;
    ret = f(cura + 1, curb);
    if (a[cura] > b[curb]) {
        ret = max(ret,f(cura, curb + 1)+ b[curb]);
    }
    else {
        ret = max(ret, f(cura+1, curb + 1));
    }    
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << f(0,0);
    return 0;
}