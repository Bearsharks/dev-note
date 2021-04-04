#include <iostream>
using namespace std;

long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val, deg >> 1, mod);
    return (res * res) % mod;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b,c;
    cin >> a >> b >> c;
    cout << binpow(a, b, c);
    return 0;
}


