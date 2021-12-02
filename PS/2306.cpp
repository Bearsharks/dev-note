#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(501,vector<int>(501, -1));
string str;
int f(int s, int e) {
    if (e <= s) return 0;
    int& ret = v[s][e];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = s; i < e; i++) {
        ret = max(ret, f(s, i) + f(i + 1, e));
    }
    if (str[s] == 'a' && str[e] == 't') ret = max(f(s + 1, e - 1) + 2, ret);
    else if (str[s] == 'g' && str[e] == 'c') ret = max(f(s + 1, e - 1) + 2, ret);
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> str;
    cout << f(0,str.size()-1);

    return 0;
}