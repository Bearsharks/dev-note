#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<unsigned long long> v(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    unsigned long long last = 0;
    for (int i = 0; i < m; i++) {
        unsigned long long w, h;
        cin >> w >> h;
        last = max(v[w], last);
        cout << last << "\n";
        last += h;
    }
    return 0;
}