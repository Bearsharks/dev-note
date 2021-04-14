#include <iostream>
using namespace std;

unsigned long long M = 1e9 + 7;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    unsigned long long ans = 1;
    for (int i = 0; i < k - 1; i++) {
        ans = (ans * k) % M;
    }
    int out = n - k;
    for (int i = 0; i < out; i++) {
        ans = (ans * out) % M;
    }
    
    cout << ans;
    return 0;
}