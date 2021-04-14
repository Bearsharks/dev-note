#include <iostream>
#include <set>
using namespace std;
unsigned long long gcd(unsigned long long u, unsigned long long v) {
    if (v == 0) {
        return u;
    }
    else {
        return gcd(v, u % v);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unsigned long long n;
	cin >> n;

    set<unsigned long long> ans;
    ans.insert(1);

    for (unsigned long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            unsigned long long g = gcd(i, n);
            unsigned long long cnt = n / g;
            ans.insert((2 + (cnt - 1) * i) * cnt / 2);
            g = gcd(n / i, n);
            cnt = n / g;
            ans.insert((2 + (cnt - 1) * n / i) * cnt / 2);
        }
        
    }
    ans.insert(n*(n+1) / 2);

    for (unsigned long long i : ans) {
        cout << i << " ";
    }
	return 0;
}