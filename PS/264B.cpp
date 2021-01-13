#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int last = v.back();
    vector<int> isPrime(last + 1, 0);
    vector<int> primes;
    isPrime[0] = -1;
    isPrime[1] = -1;
    for (int i = 2; i * i <= last; i++) {
        if (isPrime[i] == 0) {
            for (int j = i*i; j <= last; j += i) {
                isPrime[j] = -1;
            }
        }
    }

    for (int i = 2; i < last + 1; i++) {
        if (isPrime[i] >= 0) {
            primes.push_back(i);
        }        
    }

    int ans = 1;
    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++) {        
        if (isPrime[*i] >= 0  || *i == 1) {
            ans = max(++isPrime[*i], ans);
            continue;
        }
        unordered_set<int> divisors;
        int cur = *i;
        for (int j = 0; primes[j] <= cur; j++) {
            if (cur % primes[j] == 0) {
                divisors.insert(primes[j]);
                cur /= primes[j];
            }
        }
        int mx = 1;
        for (int k : divisors) {
            mx = max(++isPrime[k], mx);
        }
        for (int k : divisors) {
            isPrime[k] = mx;
        }
        ans = max(mx, ans);
    }

    cout << ans;
    return 0;
}