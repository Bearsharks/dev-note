#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int i = 0;
    int n = s.size();
    for (; i < n; i++) {
        if (s.at(i) == '[') break;
    }
    for (; i < n; i++) {
        if (s.at(i) == ':') break;
    }
    int j = n-1;
    for (; j > 0 ; j--) {
        if (s.at(j) == ']') break;
    }
    for (; j > 0; j--) {
        if (s.at(j) == ':') break;
    }

    if (i >= j) cout << -1;
    else {
        int cnt = 0;
        for (; i < j; i++) {
            if (s.at(i) == '|') cnt++;
        }
        cout << cnt + 4;
    }
    return 0;
}