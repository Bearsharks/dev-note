#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stringstream ss;
    ss << "<3";
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        ss << a << "<3";
    }
    string s = ss.str();
    string msg;
    cin >> msg;

    int i = -1;
    int cur = 0;
    int ssize = s.size();
    int msize = msg.size();

    while (i < msize && cur < ssize) {
        i++;
        if (msg[i] == s[cur]) {
            cur++;
        }
        
    }
    string ans = (i == msize) ? "no" : "yes";
    cout << ans;
    return 0;
}