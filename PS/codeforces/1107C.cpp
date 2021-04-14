#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt(vector<char>& k, int i) {
    for (; i < k.size()-1; i++) {
        if (k[i] != k[i + 1]) break;
    }
    return i;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> dmg(n);
    vector<char> key(n);
    for (int i = 0; i < n; i++) {
        cin >> dmg[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> key[i];
    }
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++) {
        int next = cnt(key, i);
        sort(dmg.begin() + i, dmg.begin() + next + 1);
        for (int j = next; j >= i && j > next - k ; j--) {
            ans += dmg[j];
        }
        i = next;
    }
    cout << ans;
    return 0;
}