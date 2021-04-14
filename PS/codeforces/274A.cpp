#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    set< long long> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    if ( k == 1) {
        cout << n;
        return 0;
    }

    for (set<long long>::iterator i = s.begin(); i != s.end(); i++) {
        if (s.count(*i * k)) {
            s.erase(*i * k);
        }
    }
    cout << s.size();
    return 0;
}