#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int i = 0;
    long long curmn = 987665543321;
    long long a, b;
    while (i < n && v[i] < 0) {
        vector<long long>::iterator iter = lower_bound(v.begin(), v.end(), -v[i]);
        if (iter != v.end() && v[i] < *iter && curmn > abs(v[i] + *iter)) {
            curmn = abs(v[i] + *iter);
            a = v[i];
            b = *iter;
        }
        iter--;
        if (v[i] < *iter && curmn > abs(v[i] + *iter)) {
            curmn = abs(v[i] + *iter);
            a = v[i];
            b = *iter;
        }
        i++;
    }
    if (i + 1 < n) {
        if (curmn > abs(v[i] + v[i + 1])) {
            a = v[i];
            b = v[i + 1];
        }
    }
    cout << a << " " << b;
    return 0;
}