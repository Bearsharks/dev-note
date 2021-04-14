#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    bitset<32> b1(n);
    int min = b1.count();
    int max = n;
    if (k < min || k > max) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int v[32];
    for (int i = 0; i < 32; i++) {
        v[i] = b1[i];
    }
    int cur = b1.count();

    int i = 31;
    while (cur < k) {
        while (v[i] == 0) {
            i--;
        }

        while (v[i] > 0 && cur < k) {
            v[i]--;
            v[i - 1] += 2;
            cur++;
        }
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << (1 << i) << " ";
        }
    }
    return 0;
}


