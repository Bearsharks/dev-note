#include <iostream>
#include <vector>
#include<sstream>
using namespace std;

int s, f, dir;
char dirc;
stringstream ans;
void pass(int t) {
    if (s == f) return;
    while (t-- && s != f) {
        s += dir;
        ans << dirc;
    }
    return;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m >> s >> f;
    dir = (s < f)? 1 : -1;
    dirc = (dir == 1) ? 'R' : 'L';
    
    int prevt = 0;    
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;            
        pass(t - prevt - 1);
        if (s == f) {
            break;
        }
        prevt = t;
        if ((r < s || s < l) && (r < s + dir || s + dir < l)) {
            pass(1);
        }
        else {
            ans << 'X';
        }
    }
    pass(INT_MAX);
    cout << ans.str();
    return 0;
}

