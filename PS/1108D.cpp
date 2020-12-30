#include <iostream>
#include<map>
using namespace std;

int cnt(string& s, int i) {
    for (; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) break;
    }
    return i;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    
    string q = "RGB";
    char c = q.erase(s.back(), 1)[0];
    s += c;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int next = cnt(s, i);
        if (i != next) {
            q = "RGB";
            q.erase(q.find(s[i]), 1);
            q.erase(q.find(s[next+1]), 1);
            c = q[0];
            for (int j = i + 1; j <= next && j < n; j += 2) {
                s[j] = c;
                ans++;
            }
            i = next;
        }
    }
    s.pop_back();
    cout << ans << "\n" << s;


    return 0;
}